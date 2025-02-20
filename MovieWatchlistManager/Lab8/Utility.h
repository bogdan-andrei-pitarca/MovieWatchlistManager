#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
class Utility
{
public:
	void trim(std::string& input);
	std::vector<std::string> tokenize(std::string input, char separator);
};
