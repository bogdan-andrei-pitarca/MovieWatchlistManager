#include "Validator.h"
void Validator::validateTitle(string title) {
	if (title.empty()) throw invalid_argument("Title can't be empty!\n");
}
void Validator::validateGenre(string genre) {
	if (genre.empty()) throw invalid_argument("Genre can't be empty!\n");
}
void Validator::validateYear(string year) {
	int year2;
	try {
		year2 = stoi(year);
	}
	catch (exception&) {
		throw invalid_argument("Year must be an integer!\n");
	}
	if (year2 < 0) throw invalid_argument("Year must be positive!\n");
}
void Validator::validateLikes(string likes) {
	int likes2;
	try {
		likes2 = stoi(likes);
	}
	catch (exception&) {
		throw invalid_argument("Number of likes must be an integer!\n");
	}
}
void Validator::validateTrailer(string trailer) {
	const regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
	if (!regex_match(trailer, pattern))
		throw invalid_argument("Invalid trailer!\n");
}
void Validator::validateMovie(string title, string genre, string year, string likes, string trailer) {
	vector<invalid_argument> errors;
	try {
		validateTitle(title);
	}
	catch (invalid_argument& error) {
		errors.push_back(error);
	}
	try {
		validateGenre(genre);
	}
	catch (invalid_argument& error) {
		errors.push_back(error);
	}
	try {
		validateYear(year);
	}
	catch (invalid_argument& error) {
		errors.push_back(error);
	}
	try {
		validateLikes(likes);
	}
	catch (invalid_argument& error) {
		errors.push_back(error);
	}
	try {
		validateTrailer(trailer);
	}
	catch (invalid_argument& error) {
		errors.push_back(error);
	}
	if (errors.size() != 0) throw MovieException(errors);
}