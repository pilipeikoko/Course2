#pragma once
#include "Exceptions.h"

class Math_error :public Error {
public:
	Math_error(string message) :Error(message) {};
	string get_message() { return this->message; }
};
