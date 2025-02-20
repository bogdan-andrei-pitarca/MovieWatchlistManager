#include "Repository.h"
#include "Exception.h"
#include <iostream>
using namespace std;
Repository::Repository() {
    this->movies = std::vector<Movie>();
}
Repository::~Repository() {

}
void Repository::addMovie(const Movie& movie) {
    this->movies.push_back(movie);
}
void Repository::deleteMovie(const Movie& movie) {
    auto it = std::find(this->movies.begin(), this->movies.end(), movie);
    if (it != this->movies.end()) {
        this->movies.erase(it);
        std::cout << "Movie successfully removed!\n";
    }
    else {
        std::cout << "Movie not found in the repository!\n";
    }
}
void Repository::updateMovie(int position, Movie& newMovie) {
    this->movies[position] = newMovie;
}
bool Repository::isValidPosition(int position) {
    if (position >= 0 && position < this->movies.size()) return true;
    return false;
}
std::vector<Movie> Repository::getMovies() {
    return this->movies;
}
int Repository::getLength() {
    return this->movies.size();
}
int Repository::getPosition(Movie& movie) {
    auto it = std::find(this->movies.begin(), this->movies.end(), movie);
    if (it == this->movies.end())
        return -1;
    return std::distance(this->movies.begin(), it);
}
bool Repository::movieExists(const string& title) {
    for (int i = 0; i < this->movies.size(); i++)
        if (this->movies[i].getTitle() == title) return true;
    return false;
}
Movie Repository::getMovie(int position) {
    if (position < 0 || position >= this->movies.size())
        throw std::invalid_argument("Invalid position! ");
    return this->movies[position];
}
void Repository::removeIndexed(int position) {
    this->movies.erase(this->movies.begin() + position);
}
void Repository::modifyLikes(int position, int likes) {
    Movie movie = this->getMovie(position);
    movie.setLikes(movie.getLikes() + likes);
    this->updateMovie(position, movie);
}
void Repository::clearData() {
    this->movies.clear();
}