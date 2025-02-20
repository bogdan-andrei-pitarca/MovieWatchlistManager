#include "Service.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Service::Service() {
	this->repository = nullptr;
	this->credentials = false;
	this->watchlist = nullptr;
	this->index = 0;
}
Service::~Service() {
	delete this->watchlist;
	delete this->repository;
}
bool Service::getCredentials() {
	return this->credentials;
}
void Service::setCredentials(bool credentials) {
	this->credentials = credentials;
}
void Service::addMovie(Movie movie) {
	if (this->repository->movieExists(movie.getTitle()))
		throw DuplicateException();
	this->repository->addMovie(movie);
}
void Service::removeMovie(string& title) {
	if (!this->repository->movieExists(title)) throw InvalidPositionException();
	for (auto& movie : this->repository->getMovies())
		if (movie.getTitle() == title) {
			this->repository->deleteMovie(movie);
		}
}
void Service::updateMovie(int position, Movie newMovie) {
	if (!this->repository->isValidPosition(position)) throw InvalidPositionException();
	if (this->repository->getPosition(newMovie) != -1)  throw DuplicateException();
	this->repository->updateMovie(position, newMovie);
}
void Service::hardCodedMovies() {
	std::vector<Movie> moviesToAdd = {
		Movie("The Shawshank Redemption", "Drama", 1994, 0, "https://www.youtube.com/watch?v=6hB3S9bIaco"),
		Movie("The Godfather", "Crime", 1972, 0, "https://www.youtube.com/watch?v=sY1S34973zA"),
		Movie("The Dark Knight", "Action", 2008, 0, "https://www.youtube.com/watch?v=EXeTwQWrcwY"),
		Movie("Pulp Fiction", "Crime", 1994, 0, "https://www.youtube.com/watch?v=s7EdQ4FqbhY"),
		Movie("The Grand Budapest Hotel", "Comedy", 2013, 0, "https://www.youtube.com/watch?v=rVnvyKnOOxI"),
		Movie("Zodiac", "Thriler", 2007, 0, "https://www.youtube.com/watch?v=QvPvSnkUwGs"),
		Movie("Get Out", "Horror", 2017, 0, "https://www.youtube.com/watch?v=sRfnevzM9kQ"),
		Movie("Parasite", "Drama", 2019, 0, "https://www.youtube.com/watch?v=5xH0HfJHsaY"),
		Movie("City of God", "Drama", 2002, 0, "https://www.youtube.com/watch?v=ioUE_5wpg_E"),
		Movie("The Hunt", "Drama", 2012, 0, "https://www.youtube.com/watch?v=rVnvyKnOOxI"),
		Movie("The Good, the Bad and the Ugly", "Western", 1966, 0, "https://www.youtube.com/watch?v=WCN5JJY_wiA"),
		Movie("Inception", "Action", 2010, 0, "https://www.youtube.com/watch?v=YoHD9XEInc0"),
		Movie("Forrest Gump", "Drama", 1994, 0, "https://www.youtube.com/watch?v=bLvqoHBptjg"),
		Movie("Schindler's List", "Biography", 1993, 0, "https://www.youtube.com/watch?v=gG22XNhtnoY"),
		Movie("2012", "Action", 2009, 0, "https://www.youtube.com/watch?v=sFXGrTng0gQ")
	};

	for (const auto& movie : moviesToAdd) {
		if (!this->repository->movieExists(movie.getTitle())) {
			this->addMovie(movie);
		}
	}
}

Movie Service::getMovie(int position) {
	if (!this->repository->isValidPosition(position))
		throw InvalidPositionException();
	return this->repository->getMovie(position);
}
int Service::getSize() {
	return this->repository->getLength();
}
std::vector<Movie> Service::getAllMovies() {
	return this->repository->getMovies();
}
bool Service::movieExists(string& title) {
	return this->repository->movieExists(title);
}
void Service::openTrailer(int position) {
	Movie movie = this->getMovie(position);
	string link = movie.getTrailer();
	string command = "start " + link;
	system(command.c_str());
}
bool Service::cmpstr(string& str1, string& str2) {
	if (str1.size() != str2.size()) return false;
	for (int i = 0; str1[i]; ++i)
		if (tolower(str1[i]) != tolower(str2[i])) return false;
	return true;
}
void Service::userRemove(int position) {
	this->watchlist->removeMovie(position);
}
void Service::adminRemoveByPosition(int position) {
	if (!this->repository->isValidPosition(position)) throw InvalidPositionException();
	this->repository->removeIndexed(position);
}
std::vector<Movie> Service::getMoviesFromWatchlist() {
	return this->watchlist->getMovies();
}
std::vector<Movie> Service::getMoviesByGenre(string genre) {
	moviesByGenre.clear();
	index = 0;
	for (auto& movie : this->repository->getMovies()) {
		std::string genreOfCurrentMovie = movie.getGenre();
		if (genre == "" || (this->cmpstr(genreOfCurrentMovie, genre)))
			this->moviesByGenre.push_back(movie);
	}
	return moviesByGenre;
}
void Service::increment() {
	this->index++;
}
Movie Service::getCurrentMovie() {
	if (this->index == this->moviesByGenre.size()) this->index = 0;
	this->openCurrentTrailer();
	return this->moviesByGenre[this->index];
}
void Service::openCurrentTrailer() {
	Movie currentMovie = this->moviesByGenre[this->index];
	currentMovie.openTrailer();
}
void Service::addCurrentMovie() {
	this->userAdd(this->moviesByGenre[this->index]);
}
void Service::removeWatchedMovie(int position, bool liked) {
	Movie currentMovie = this->watchlist->getByPosition(position);
	if (liked) {
		for (auto movie : this->repository->getMovies()) {
			if (movie == currentMovie) {
				this->increaseLikes(movie);
				break;
			}
		}
	}
	this->watchlist->removeMovie(position);
}
void Service::userAdd(Movie& movie) {
	this->watchlist->isMovieIn(movie);
	this->watchlist->addMovie(movie);
}
void Service::increaseLikes(Movie& movie) {
	int position = this->repository->getPosition(movie);
	this->repository->modifyLikes(position, 1);
}
void Service::setWatchlistType(FileWatchlist* fw) {
	this->watchlist = fw;
}
void Service::setRepositoryType(Repository* repo) {
	this->repository = repo;
	this->repository->loadMovies();
}
void Service::display() {
	this->watchlist->openExtern();
}
void Service::isInWatchlist(Movie& movie) {
	this->watchlist->isMovieIn(movie);
}
void Service::clearFile(string filename) {
	ofstream file(filename);
	file.close();
}