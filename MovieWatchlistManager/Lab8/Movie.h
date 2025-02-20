#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include "Utility.h"
#include "Exception.h"
#include "Validator.h"
#include <iostream>
#include <string>
using namespace std;
class Movie
{
private:
	string title;
	string genre;
	int yearOfRelease;
	int nrOfLikes;
	string trailer;
public:
	Movie(const string& title = "", const string& genre = "", int yearOfRelease = 0, int nrOfLikes = 0, const string& trailer = "");
	Movie(const Movie& movie);
	string getTitle() const;
	string getGenre() const;
	int getYear() const;
	int getLikes() const;
	string getTrailer() const;
	void setTitle(string& title);
	void setGenre(string& genre);
	void setTrailer(string& trailer);
	void setYear(int yearOfRelease);
	void setLikes(int nrOfLikes);
	bool isValidTrailer(string trailer);
	bool isValidYear(int yearOfRelease);
	bool isValidLikes(int nrOfLikes);
	bool isValidMovie();
	void openTrailer();
	Movie& operator=(const Movie& movie);
	bool operator==(const Movie& movie);
	friend std::ostream& operator<<(std::ostream& out, Movie& movie);
	friend std::istream& operator>>(std::istream& in, Movie& movie);
};

#endif // MOVIE_H