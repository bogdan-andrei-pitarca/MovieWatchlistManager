#pragma once
#ifndef SERVICE_H
#define SERVICE_H
#include "Repository.h"
#include "Validator.h"
#include "Watchlist.h"
#include "FileWatchlist.h"
#include <iostream>
#include <string>
class Service
{
private:
	Repository* repository;
	bool credentials;
	std::vector<Movie> moviesByGenre;
	FileWatchlist* watchlist;
	int index;

public:
	Service();
	~Service();
	void addMovie(Movie movie);
	void removeMovie(string& title);
	void updateMovie(int position, Movie newMovie);
	int getSize();
	Movie getMovie(int position);
	bool getCredentials();
	void setCredentials(bool credentials);
	std::vector<Movie> getAllMovies();
	bool movieExists(string& title);
	void hardCodedMovies();
	void openTrailer(int position);
	bool cmpstr(string& str1, string& str2);
	void userRemove(int position);
	std::vector<Movie> getMoviesByGenre(string genre);
	std::vector<Movie> getMoviesFromWatchlist();
	void userAdd(Movie& movie);
	void increaseLikes(Movie& movie);
	void setWatchlistType(FileWatchlist* fw);
	void setRepositoryType(Repository* repo);
	void display();
	void isInWatchlist(Movie& movie);
	void clearFile(string file);
	void increment();
	Movie getCurrentMovie();
	void openCurrentTrailer();
	void addCurrentMovie();
	void removeWatchedMovie(int position, bool liked);
	void adminRemoveByPosition(int position);
};

#endif // SERVICE_H

