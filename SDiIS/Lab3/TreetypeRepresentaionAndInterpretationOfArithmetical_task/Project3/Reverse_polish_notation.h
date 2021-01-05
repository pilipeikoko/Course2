#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <cctype>
#include "Line_error.h"

using namespace std;

bool is_operator(string ch);

class Reverse_polish_notation
{
	vector <string> notation;

	char opposite_sign(char ch);
	string unary_minus(string line);
	bool try_parse_number(string symbol);
	int priority(string ch);
	bool is_sign(char ch);

public:
	vector<string> get_notation();
	void make_notation(string line) throw (Line_error);
	void print_notation();
};