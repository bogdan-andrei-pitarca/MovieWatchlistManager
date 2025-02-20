#include "Utility.h"
void Utility::trim(std::string& input) {
	while (!input.empty() && input[0] == ' ') input.erase(0, 1);
	while (!input.empty() && input[input.size() - 1] == ' ') input.erase(input.size() - 1, 1);
}
std::vector<std::string> Utility::tokenize(std::string input, char separator) {
	std::vector<std::string> tokens;
	std::istringstream tokenStream(input);
	std::string token;
	while (getline(tokenStream, token, separator)) {
		trim(token);
		tokens.push_back(token);
	}
	return tokens;
}