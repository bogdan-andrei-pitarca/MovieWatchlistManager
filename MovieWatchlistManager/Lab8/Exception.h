#pragma once
#include <string>
#include <vector>
#include <exception>
#include <iostream>
class FileException : public std::exception
{
private:
	std::string message;
public:
	FileException(std::string message);
	virtual const char* what();
};
class RepositoryException : public std::exception {
protected:
	std::string message;
public:
	RepositoryException();
	RepositoryException(std::string message);
	virtual ~RepositoryException() {};
	virtual const char* what();
};
class DuplicateException : public RepositoryException
{
public:
	const char* what();
};
class InvalidPositionException : public RepositoryException
{
public:
	const char* what();
};
class MovieException : public std::exception
{
private:
	std::vector<std::invalid_argument> errors;

public:
	MovieException(std::vector<std::invalid_argument> errors);
	MovieException(std::string error);
	std::vector<std::invalid_argument> returnErrors();
};

