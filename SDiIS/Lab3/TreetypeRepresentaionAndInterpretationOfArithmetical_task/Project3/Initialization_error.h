#pragma once
#include "Exceptions.h"

class Initizalization_error :public Error {
public:
	Initizalization_error(string message) :Error(message) {};
	string get_message() { return this->message; }
};
