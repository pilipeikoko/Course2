#pragma once
#include "Reverse_polish_notation.h"
#include "Expression_tree.h"
#include <math.h>

class Functions
{
	void replace_sqrt(string& line) throw (Line_error);
	void replace_sin(string& line) throw (Line_error);
	void replace_cos(string& line) throw (Line_error);
	void replace_ctg(string& line) throw (Line_error);
	void replace_log(string& line) throw (Line_error);
	void replace_tg(string& line) throw (Line_error);

public:
	string function_processing(string& line);
};