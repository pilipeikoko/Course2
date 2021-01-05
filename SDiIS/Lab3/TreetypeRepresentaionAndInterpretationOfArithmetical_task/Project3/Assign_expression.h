#pragma once
#include "Expression.h"
#include "Initialization_error.h"

class Assign_expression: protected Expression {
	vector <pair<string, int>> variables;

public:
	void memory_clear();
	bool is_assgignment(string& line);
	void put_variables_into_kb(string line) throw (Initizalization_error);
	string assign_variables(string line);
};