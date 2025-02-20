#include "HTMLWatchlist.h"
#include "Exception.h"
#include <fstream>
void HTMLWatchlist::writeToFile() const {
	std::ofstream out(this->filename.c_str());
	if (!out.is_open()) throw FileException("Can't open that!\n");
	out << "<!DOCTYPE html> <html> <head> <title> WATCHLIST:</title> </head > <body> <table border=\"1\">";
	out << "<tr> <td> INDEX </td> <td> TITLE </td> <td> GENRE </td> <td> YEAR </td> <td> LIKES </td> <td> TRAILER </td> </tr>";
	int i = 1;
	for (auto& movie : movies)
		out << "<tr> <td>" << i++ << "</td> <td>" << movie.getTitle() << "</td> <td>" << movie.getGenre() << "</td> <td>" << movie.getYear() << "</td> <td>" << movie.getLikes() << "</td> <td><a href=\"" << movie.getTrailer() << "\"> Link</a></ td> </tr>";
	out << "</table> </body> </html>";
	out.close();
}