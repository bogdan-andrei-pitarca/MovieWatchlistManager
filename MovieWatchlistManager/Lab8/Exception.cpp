#include "Exception.h"
FileException::FileException(std::string message) : message{ message } {}
const char* FileException::what() {
	return this->message.c_str();
}
RepositoryException::RepositoryException() : std::exception() {
	this->message = "";
}
RepositoryException::RepositoryException(std::string message) : message{ message } {}
const char* RepositoryException::what() {
	return this->message.c_str();
}
const char* DuplicateException::what() {
	return "Movie already in!";
}
const char* InvalidPositionException::what() {
	return "Invalid position!";
}
MovieException::MovieException(std::string error) {
	this->errors.push_back(std::invalid_argument(error));
}
MovieException::MovieException(std::vector<std::invalid_argument> errors) {
	this->errors = errors;
}
std::vector<std::invalid_argument> MovieException::returnErrors() {
	return this->errors;
}