#include "Assign_expression.h"

void Assign_expression::memory_clear()
{
	variables.clear();
}

bool Assign_expression::is_assgignment(string& line)
{
	this->remove_spaces(line);

	bool assign_pointer = false;

	if (line.find_last_of('=') != -1) {
		assign_pointer = true;
	}

	return assign_pointer;
}

void Assign_expression::put_variables_into_kb(string line) throw (Initizalization_error)
{
	int num_to_assign;
	string variable_to_asign;
	int i = line.find_last_of('=');

	line = '=' + line;

	for (int j = i + 2; j < line.length(); j++) {
		if (!isdigit(line[j]) && line[j] != '-')
			throw Initizalization_error("You cant assign a letter\n");
	}

	if (line.length() - 1 == i + 1)
		throw Initizalization_error("Nothing to assign\n");

	num_to_assign = stoi(line.substr(i + 2));

	for (int j = 0; j <= i; j++) {
		if (line[j] == '=') {
			j++;
			while (line[j] != '=') {
				variable_to_asign += line[j];
				j++;
			}
			j--;
			if (!isalpha(variable_to_asign[0]))
				throw Initizalization_error("First letter of variable should be a letter\n");
			variables.push_back(make_pair(variable_to_asign, num_to_assign));
			variable_to_asign = "";
		}
	}
}

string Assign_expression::assign_variables(string line)
{
	int assign_index;

	for (int i = 0; i < variables.size(); i++) {
		while (line.find(variables[i].first) != -1) {
			assign_index = line.find(variables[i].first);
			line.erase(assign_index, variables[i].first.length());
			line.insert(assign_index, to_string(variables[i].second));
		}
	}

	return line;
}
