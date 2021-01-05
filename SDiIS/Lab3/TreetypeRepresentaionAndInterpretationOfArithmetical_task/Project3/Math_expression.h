#pragma once
#include "Expression.h"

class Math_expression : protected Expression {
public:
	int compute_value(string line);
};