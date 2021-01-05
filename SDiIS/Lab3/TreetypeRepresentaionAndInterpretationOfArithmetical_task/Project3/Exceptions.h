#pragma once
#include <iostream>
#include <string>

using namespace std;

class Error {
protected:
	string message = "";

public:

	Error(string message) { this->message = message; }
	virtual string get_message() = 0;
};

