#pragma once
#include "FileWatchlist.h"
class HTMLWatchlist : public FileWatchlist
{
public:
	HTMLWatchlist(std::string filename) : FileWatchlist(filename) {};
	void writeToFile() const override;
};



