#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <cctype>
#include "Expression_tree.h"
#include "Users_functions.h"
#include "Exceptions.h"

using namespace std;

class Expression {
protected:
	bool is_number(string line);
	void remove_spaces(string& line);
};