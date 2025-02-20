#ifndef FILEREPO_H
#define FILEREPO_H
#pragma once
#include "Repository.h"
class FileRepo : public Repository
{
private:
	std::string filename;
public:
	FileRepo(std::string filename);
	virtual ~FileRepo();
	void loadMovies();
	void saveMovies();
	void addMovie(Movie& m);
	void removeMovie(Movie& m);
	void removeIndexed(int position);
	void updateMovie(int position, Movie& newMovie);
};

#endif // FILEREPO_H