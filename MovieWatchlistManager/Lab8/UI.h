#pragma once
#ifndef UI_H
#define UI_H
#include <iostream>
#include <string>
#include "Service.h"
#include "FileRepo.h"
class UI
{
private:
	Service service;
public:
	UI();
	~UI();
	void printMainMenu();
	void printAdminMenu();
	void printUserMenu();
	void printMovies();
	void addMovie();
	void deleteMovie();
	void updateMovie();
	void userGetByGenre();
	void userDisplayWatchlist();
	void userDelete();
	void run();
	void chooseFileType();
	void clearFile();
};

#endif // UI_H

