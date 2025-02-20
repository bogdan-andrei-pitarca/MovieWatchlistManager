#include "Movie.h"
#include <iostream>
#include <regex>
#include <exception>
#include <ctime>
using namespace std;
/*constructor for the Movie class
@param: title - string representing the title
@param: genre - string representing the genre
@param: yearOfRelease - int representing the year of release
@param: nrOfLikes - int represnting the nr of likes
@param: trailer - string representing the trailer
@returns: -*/
Movie::Movie(const string& title, const string& genre, int yearOfRelease, int nrOfLikes, const string& trailer) {
	this->title = title;
	this->genre = genre;
	this->yearOfRelease = yearOfRelease;
	this->nrOfLikes = nrOfLikes;
	this->trailer = trailer;
}
/*copy constructor for the movie class
@param: movie - Movie for the copy constructor
@returns: -
*/
Movie::Movie(const Movie& movie) {
	this->title = movie.title;
	this->genre = movie.genre;
	this->trailer = movie.trailer;
	this->yearOfRelease = movie.yearOfRelease;
	this->nrOfLikes = movie.nrOfLikes;
}
/*getter for the title
@params: -
@returns: title of Movie*/
string Movie::getTitle() const {
	return this->title;
}
/*getter for the genre
@params: -
@returns: genre of Movie*/
string Movie::getGenre() const {
	return this->genre;
}
/*getter for the trailer
@params: -
@returns: trailer of Movie*/
string Movie::getTrailer() const {
	return this->trailer;
}
/*getter for the year
@params: -
@returns: release year of Movie*/
int Movie::getYear() const {
	return this->yearOfRelease;
}
/*getter for the likes
@params: -
@returns: nr of likes of Movie
*/
int Movie::getLikes() const {
	return this->nrOfLikes;
}
/*setter for the title
@params: string representing the new title
@returns: -
*/
void Movie::setTitle(string& title) {
	this->title = title;
}
/*setter for the genre
@params: string representing the new genre
@returns: -
*/
void Movie::setGenre(string& genre) {
	this->genre = genre;
}
/*setter for the trailer
@params: string representing the new trailer
@returns: -
*/
void Movie::setTrailer(string& trailer) {
	this->trailer = trailer;
}
/*setter for the year
@params: int representing the new year of release
@returns: -
*/
void Movie::setYear(int yearOfRelease) {
	if (this->isValidYear(yearOfRelease))
		this->yearOfRelease = yearOfRelease;
	else throw exception();
}
/*setter for the likes
@params: int representing the new nr of likes
@returns: -
*/
void Movie::setLikes(int nrOfLikes) {
	if (this->isValidLikes(nrOfLikes))
		this->nrOfLikes = nrOfLikes;
	else throw exception();
}
/*
function that checks whether a trailer is valid
@params: string representing the trailer
@returns: true, if it is valid (of type link)
@returns: false, if it is invalid
*/
bool Movie::isValidTrailer(string trailer) {
	const regex pattern("(http|https)://(www\\.)?youtube\\.com/watch\\?v=[\\w-]{11}");
	if (!regex_match(trailer, pattern))
		return false;
	return true;
}
/*function that gets the current year
@params: -
@returns: int representing the current year
*/
int currentYear() {
	time_t currentTime;
	struct tm timeInfo;
	time(&currentTime);
	localtime_s(&timeInfo, &currentTime);
	int year = timeInfo.tm_year + 1900;
	return year;
}
/*function that checks whether a year of release is valid
@params: int representing the year of release
@returns: true, if it is positive and less than the current year
@returns: false, otherwise
*/
bool Movie::isValidYear(int yearOfRelease) {
	if (yearOfRelease < 0 || yearOfRelease > currentYear())
		return false;
	return true;
}
/*
function that checks whether a movie's number of likes is valid
@params: int representing the number of likes
@returns: false, if it is negative
@returns: true, otherwise
*/
bool Movie::isValidLikes(int nrOfLikes) {
	if (nrOfLikes < 0)
		return false;
	return true;
}
/*
function that checks whether the movie is valid, as a whole
@params: -
@returns: true, if all isValid functions return true
@returns: false, otherwise
*/
bool Movie::isValidMovie() {
	if (isValidTrailer(this->trailer) && isValidLikes(this->nrOfLikes) && isValidYear(this->yearOfRelease))
		return true;
	return false;
}
/*
assignment operator function
@params: Movie
@returns: pointer to assigned movie
*/
Movie& Movie::operator=(const Movie& movie) {
	if (this == &movie) return *this;
	this->title = movie.title;
	this->genre = movie.genre;
	this->trailer = movie.trailer;
	this->yearOfRelease = movie.yearOfRelease;
	this->nrOfLikes = movie.nrOfLikes;
	return *this;
}
/*
equality operator function
@params: Movie
@returns: true, if movies are equal
@returns: false, otherwise
*/
bool Movie::operator==(const Movie& movie) {
	if (this->title == movie.title && this->genre == movie.genre && this->yearOfRelease == movie.yearOfRelease) return true;
	return false;
}
/*insertion operator function
@params: out (ostream)
@params: Movie movie
@returns: output
*/
std::ostream& operator<<(std::ostream& out, Movie& movie) {
	out << movie.getTitle() << " | " << movie.getGenre() << " | " << movie.getYear() << " | " << movie.getLikes() << " | " << movie.getTrailer();
	return out;
}
/*extraction operator function
@params: in (istream)
@params: Movie movie
@returns: input*/
std::istream& operator>>(std::istream& in, Movie& movie) {
	Utility utility;
	std::string line;
	std::getline(in, line);
	std::vector<std::string> input = utility.tokenize(line, '|');
	if (input.size() != 5) throw MovieException("Not enough arguments!");
	string title = input[0], genre = input[1], year = input[2], likes = input[3], trailer = input[4];
	Validator::validateMovie(title, genre, year, likes, trailer);
	movie.setTitle(title);
	movie.setGenre(genre);
	movie.setYear(stoi(year));
	movie.setLikes(stoi(likes));
	movie.setTrailer(trailer);
	return in;
}
/*function that externally opens the trailer*/
void Movie::openTrailer() {
	string cmd = "start " + this->trailer;
	system(cmd.c_str());
}