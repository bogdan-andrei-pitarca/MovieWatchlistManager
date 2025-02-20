#include "CSVWatchlist.h"
#include "Exception.h"
#include <fstream>
void CSVWatchlist::writeToFile() const {
	std::ofstream out(this->filename.c_str());
	if (!out.is_open()) throw FileException("Can't open that!\n");
	out << "INDEX, TITLE, GENRE, YEAR, LIKES, TRAILER\n";
	int i = 1;
	for (auto& movie : movies)
		out << i++ << ", " << movie.getTitle() << ", " << movie.getGenre() << ", " << movie.getYear() << ", " << movie.getLikes() << ", " << movie.getTrailer() << endl;
	out.close();
}