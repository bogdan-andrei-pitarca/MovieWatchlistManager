#include "FileWatchlist.h"
#include <fstream>
void FileWatchlist::openExtern() const {
	this->writeToFile();
	std::string cmd = "start " + this->filename;
	system(cmd.c_str());
}