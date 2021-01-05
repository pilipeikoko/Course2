#pragma once
#include "Exceptions.h"

class Line_error :public Error {
public:
	Line_error(string message) :Error(message) {};
	string get_message() { return this->message; }
};
