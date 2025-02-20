#include "FileRepo.h"
#include "Exception.h"
#include <fstream>
FileRepo::FileRepo(std::string filename) {
	this->filename = filename;
}
FileRepo::~FileRepo() {
	this->saveMovies();
}
void FileRepo::loadMovies() {
	std::ifstream in(this->filename);
	if (!in.is_open()) throw FileException("Couldn't open that!\n");
	Movie movie;
	while (1) {
		try {
			in >> movie;
			this->addMovie(movie);
		}
		catch (MovieException&) {
			break;
		}
	}
}
void FileRepo::saveMovies() {
	ofstream out(this->filename);
	if (!out.is_open()) throw FileException("Couldn't open that!\n");
	for (auto& movie : movies) {
		out << movie << endl;
	}
	out.close();
}
void FileRepo::addMovie(Movie& movie) {
	Repository::addMovie(movie);
	this->saveMovies();
}
void FileRepo::updateMovie(int position, Movie& movie) {
	Repository::updateMovie(position, movie);
	this->saveMovies();
}
void FileRepo::removeMovie(Movie& movie) {
	Repository::deleteMovie(movie);
	this->saveMovies();
}
void FileRepo::removeIndexed(int position) {
	Repository::removeIndexed(position);
	this->saveMovies();
}