#pragma once
#include "Watchlist.h"
class FileWatchlist : public Watchlist
{
protected:
	std::string filename;
public:
	FileWatchlist(std::string filename) : filename{ filename } {};
	virtual void writeToFile() const = 0;
	void openExtern() const;
	virtual ~FileWatchlist() {};
};
