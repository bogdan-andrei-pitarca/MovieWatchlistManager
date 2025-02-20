#pragma once
#include "FileWatchlist.h"
class CSVWatchlist : public FileWatchlist
{
public:
	CSVWatchlist(std::string filename) : FileWatchlist(filename) {};
	void writeToFile() const override;
};


