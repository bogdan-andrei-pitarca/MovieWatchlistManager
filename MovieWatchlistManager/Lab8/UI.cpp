#include "UI.h"
#include <iostream>
#include <string>
#include "Exception.h"
#include "CSVWatchlist.h"
#include "HTMLWatchlist.h"
#include "FileRepo.h"
UI::UI() {
	this->service = Service();
	this->service.setRepositoryType(new FileRepo{ "movies.txt" });
	this->service.hardCodedMovies();
	this->chooseFileType();
}
UI::~UI() {

}
void UI::chooseFileType() {
	cout << "Please choose your file type:" << endl;
	cout << "1. CSV" << endl;
	cout << "2. HTML" << endl;
	cout << "Enter option: " << endl;
	int option;
	cin >> option;
	if (option == 1) {
		this->service.setWatchlistType(new CSVWatchlist{ "CSVWatchlist.csv" });
		return;
	}
	else if (option == 2) {
		this->service.setWatchlistType(new HTMLWatchlist{ "HTMLWatchlist.html" });
		return;
	}
	else cout << "Invalid! Try again" << endl;
}
void UI::printMainMenu() {
	std::cout << "Local Movie Database | Please choose your mode of entry\n";
	std::cout << "1. Admin\n";
	std::cout << "2. User\n";
	std::cout << "3. Exit\n";
}
void UI::printAdminMenu() {
	std::cout << "ADMINISTRATOR MODE \n";
	std::cout << "1. Add movie\n";
	std::cout << "2. Remove movie\n";
	std::cout << "3. Update movie\n";
	std::cout << "4. Display movies\n";
	std::cout << "5. Exit\n";
}
void UI::printUserMenu() {
	std::cout << "USER MODE \n";
	std::cout << "1. Get movies by genre\n";
	std::cout << "2. Delete a movie from the watchlist\n";
	std::cout << "3. See watchlist\n";
	std::cout << "4. Exit\n";
}
void UI::printMovies() {
	std::vector<Movie> movies = this->service.getAllMovies();
	std::cout << "Number of movies: " << movies.size() << "\n";
	std::vector<Movie>::iterator it = movies.begin();
	for (; it != movies.end(); it++)
	{
		Movie currentMovie = *it;
		std::cout << std::distance(movies.begin(), it) + 1 << ". " << currentMovie.getTitle() << " | " << currentMovie.getGenre() << " | " << currentMovie.getTrailer() << " | " << currentMovie.getYear() << " | " << currentMovie.getLikes() << "\n";
	}
}
void UI::addMovie() {
	cout << "Enter movie: " << endl;
	Movie movie;
	try {
		cin >> movie;
	}
	catch (MovieException& e) {
		cout << "Nope, can't do that!" << endl;
		for (auto& err : e.returnErrors()) cout << err.what() << endl;
		return;
	}
	try {
		this->service.addMovie(movie);
	}
	catch (DuplicateException& e) {
		cout << e.what() << endl;
		return;
	}
	catch (RepositoryException& e) {
		cout << e.what() << endl;
		return;
	}
}
void UI::deleteMovie() {
	string title;
	std::cout << "Enter title:\n";
	std::getline(cin, title);
	try {
		this->service.removeMovie(title);
	}
	catch (RepositoryException& e) {
		cout << e.what() << endl;
		return;
	}
}
void UI::updateMovie() {
	int position;
	std::cout << "Enter position:\n";
	cin >> position;
	Movie movie;
	try {
		movie = this->service.getMovie(position - 1);
	}
	catch (InvalidPositionException& e) {
		cout << e.what() << endl;
		return;
	}
	string title, genre, trailer, year, likes;
	title = movie.getTitle();
	genre = movie.getGenre();
	trailer = movie.getTrailer();
	year = to_string(movie.getYear());
	likes = to_string(movie.getLikes());
	string input;
	cin.ignore();
	cout << "Enter the title: ";
	getline(cin, input);
	if (input != "") title = input;
	cout << "Enter the genre: ";
	getline(cin, input);
	if (input != "") genre = input;
	cout << "Enter the year: ";
	getline(cin, input);
	if (input != "") year = input;
	cout << "Enter the likes: ";
	getline(cin, input);
	if (input != "") likes = input;
	cout << "Enter the trailer: ";
	getline(cin, input);
	if (input != "") trailer = input;
	Movie newMovie;
	try {
		Validator::validateMovie(title, genre, year, likes, trailer);
		newMovie.setTitle(title);
		newMovie.setGenre(genre);
		newMovie.setYear(stoi(year));
		newMovie.setTrailer(trailer);
		newMovie.setLikes(stoi(likes));
	}
	catch (MovieException& e) {
		cout << "Error! Couldn't update!" << endl;
		for (auto& err : e.returnErrors()) cout << err.what() << endl;
		return;
	}
	try {
		this->service.updateMovie(position - 1, newMovie);
	}
	catch (InvalidPositionException& e) {
		cout << e.what() << endl;
		return;
	}
	catch (DuplicateException& e) {
		cout << e.what() << endl;
		return;
	}
}
void UI::userGetByGenre() {
	string genre;
	std::cout << "Enter genre: ";
	std::getline(cin, genre);
	std::vector<Movie> userMovies = this->service.getMoviesByGenre(genre);
	if (userMovies.size() == 0) {
		std::cout << "No such movies available!\n";
		return;
	}
	int i = 0;
	bool loop = true;
	while (loop) {
		loop = false;
		for (auto& movie : userMovies) {
			try {
				this->service.isInWatchlist(movie);
				loop = true;
				cout << "Title: " << movie.getTitle() << endl;
				cout << "Genre: " << movie.getGenre() << endl;
				cout << "Year: " << movie.getYear() << endl;
				cout << "Likes: " << movie.getLikes() << endl;
				movie.openTrailer();
				cout << "Add it to watchlist?" << endl;
				char opt;
				cin >> opt;
				opt = tolower(opt);
				if (opt == 'y') this->service.userAdd(movie);
				else cout << "Not added to watchlist!\n";
				cout << "Wanna see the next one? (y/n): " << endl;
				cin >> opt;
				opt = tolower(opt);
				if (opt == 'n') {
					cout << "That's it!" << endl;
					return;
				}
			}
			catch (DuplicateException& e) {
				cout << e.what();
			}
		}
	}
	std::cout << "Reached the end!\n";
}
void UI::userDelete() {
	this->userDisplayWatchlist();
	std::vector<Movie> userMovies = this->service.getMoviesFromWatchlist();
	if (userMovies.size() == 0) return;
	int position;
	std::cout << "Which movie do you want to delete?\n";
	std::cin >> position;
	std::cout << "Like the movie? (y/n)\n";
	char opt;
	std::cin >> opt;
	opt = tolower(opt);
	if (opt == 'y') {
		try {
			this->service.increaseLikes(userMovies[position - 1]);
			std::cout << "Successfully liked!\n";
		}
		catch (InvalidPositionException& e) {
			cout << "Invalid position!" << endl;
			return;
		}
	}
	this->service.userRemove(position - 1);
	std::cout << "Movie removed successfully!\n";
}
void UI::userDisplayWatchlist() {
	try {
		this->service.display();
	}
	catch (FileException& e) {
		cerr << e.what() << endl;
	}
}
void UI::clearFile() {
	this->service.clearFile("movies.txt");
}
void UI::run() {
	this->printMainMenu();
	int opt = 0;
	std::cout << "Enter your option:\n";
	std::cin >> opt;
	std::cin.ignore();
	if (opt == 1) {
		this->service.setCredentials(true);
		int choice = 0;
		do {
			this->printAdminMenu();
			std::cout << "Enter option:\n";
			std::cin >> choice;
			std::cin.ignore();
			switch (choice) {
			case 1:
				this->addMovie();
				break;
			case 2:
				this->deleteMovie();
				break;
			case 3:
				this->updateMovie();
				break;
			case 4:
				this->printMovies();
				break;
			case 5:
				exit(1);
			default:
				std::cout << "Invalid option! Try again\n";
				break;
			}
		} while (choice != 5);
	}
	else if (opt == 2) {
		this->service.setCredentials(false);
		int choice = 0;
		do {
			this->printUserMenu();
			std::cout << "Enter option:\n";
			std::cin >> choice;
			std::cin.ignore();
			switch (choice) {
			case 1:
				this->userGetByGenre();
				break;
			case 2:
				this->userDelete();
				break;
			case 3:
				this->userDisplayWatchlist();
				break;
			case 4:
				exit(1);
			default:
				std::cout << "Invalid option! Try again\n";
				break;
			}
		} while (choice != 4);
	}
	else if (opt == 3) {
		std::cout << "Bye bye!\n";
		return;
	}
}