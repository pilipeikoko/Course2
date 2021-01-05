#include "Expression.h"

bool Expression::is_number(string line)
{
	bool is_number = false;

	for (int i = 0; i < line.size(); i++)
	{
		if (!isdigit(line[i]))
		{
			is_number = false;
			return is_number;
		}
		else
		{
			is_number = true;
		}
	}

	return is_number;
}

void Expression::remove_spaces(string& line)
{
	line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
}
