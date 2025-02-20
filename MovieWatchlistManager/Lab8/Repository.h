#pragma once
#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Movie.h"
#include <iostream>
#include <string>
#include <vector>
class Repository
{
protected:
	std::vector<Movie> movies;
public:
	Repository();
	virtual ~Repository();
	virtual void addMovie(const Movie& movie);
	virtual void deleteMovie(const Movie& movie);
	virtual void updateMovie(int position, Movie& newMovie);
	int getLength();
	std::vector<Movie> getMovies();
	bool isValidPosition(int position);
	int getPosition(Movie& movie);
	bool movieExists(const string& title);
	Movie getMovie(int position);
	void modifyLikes(int position, int likes);
	virtual void removeIndexed(int position);
	virtual void loadMovies() {};
	virtual void saveMovies() {};
	void clearData();
};

#endif // REPOSITORY_H