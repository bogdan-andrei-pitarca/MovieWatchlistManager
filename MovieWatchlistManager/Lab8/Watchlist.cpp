#include "Watchlist.h"
#include "Exception.h"
void Watchlist::addMovie(Movie& movie) {
	this->movies.push_back(movie);
}
void Watchlist::removeMovie(int position) {
	std::vector<Movie>::iterator it = this->movies.begin();
	std::advance(it, position);
	if (it != this->movies.end()) this->movies.erase(it);
}
void Watchlist::isMovieIn(Movie& movie) {
	for (auto& mov : movies)
		if (mov.getTitle() == movie.getTitle()) throw DuplicateException();
}
bool Watchlist::isEmpty() {
	return this->movies.size() == 0;
}
std::vector<Movie> Watchlist::getMovies() {
	return this->movies;
}
Movie Watchlist::getByPosition(int position) {
	return this->movies[position];
}