#pragma once
#include "Exception.h"
#include <string>
#include <regex>
using namespace std;
class Validator
{
public:
	static void validateTitle(string title);
	static void validateGenre(string genre);
	static void validateYear(string year);
	static void validateLikes(string likes);
	static void validateTrailer(string trailer);
	static void validateMovie(string title, string genre, string year, string likes, string trailer);
};
