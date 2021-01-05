#pragma once
#include <iostream>

class Error {
protected:
	std::string message;

public:
	Error(std::string message) { this->message = message; }
	std::string get_message() { return this->message; }
};

class Adding_error :public Error {
protected:
	int number;

public:
	Adding_error(std::string message, int number) : Error(message) { this->number = number; }
};

class Find_error :public Error {
public:
	Find_error(std::string message) :Error(message) {}
};