#pragma once
#include "Movie.h"
class Watchlist
{
protected:
	std::vector<Movie> movies;
public:
	Watchlist() {};
	virtual ~Watchlist() {};
	void addMovie(Movie& movie);
	void removeMovie(int position);
	void isMovieIn(Movie& movie);
	bool isEmpty();
	std::vector<Movie> getMovies();
	Movie getByPosition(int position);
};