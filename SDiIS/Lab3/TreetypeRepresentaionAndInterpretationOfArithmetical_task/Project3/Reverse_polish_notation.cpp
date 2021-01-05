#include "Reverse_polish_notation.h"

char Reverse_polish_notation::opposite_sign(char ch)
{
	if (ch == '-') {
		return '+';
	}
	return '-';		
}

string Reverse_polish_notation::unary_minus(string line) {
	line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

	int index_to_insert;
	string temp_line;

	while (line.find("(-") != -1) {
		index_to_insert = line.find("(-");
		line.insert(index_to_insert + 1, "0");
	}
	for (int i = 0; i < line.length() - 1; i++) {
		temp_line += line[i];
		if (!isdigit(line[i]) || !isdigit(line[i + 1]))
			temp_line += " ";
	}

	if (temp_line[0] == '-')
		temp_line.insert(0, "0 ");

	return temp_line + line.back();
}


bool Reverse_polish_notation::try_parse_number(string symbol)
{
	bool is_number = false;

	for (unsigned int i = 0; i < symbol.size(); i++)
	{
		if (!isdigit(symbol[i]))
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


int Reverse_polish_notation::priority(string ch)
{
	if (ch == "^")
	{
		return 3;
	}
	if (ch == "*" || ch == "/")
	{
		return 2;
	}
	if (ch == "+" || ch == "-")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool is_operator(string ch)
{
	return (ch == "*" || ch == "-" || ch == "+" || ch == "/" || ch == "^");
}


bool Reverse_polish_notation::is_sign(char ch)
{
	if (ch == '+' || ch == '-')
		return true;
	return false;
}


vector<string> Reverse_polish_notation::get_notation()
{
	return this->notation;
}

void Reverse_polish_notation::make_notation(string line) throw (Line_error)
{

	if (line.size() == 0) {
		throw Line_error("Line is empty!\n");
	}

	int amount_of_left_brackets = 0;
	int amount_of_right_brackets = 0;
	istringstream iss(unary_minus(line));
	vector<string> tokens;
	while (iss)
	{
		string temp;
		iss >> temp;

		if (try_parse_number(temp) && temp.size() >= 10) {
			long long b = stoll(temp.substr(0, 11));
			if (b >= 2147483647) {
				throw Line_error("Int limit overflow\n");
			}
		}

		tokens.push_back(temp);
	}

	vector<string> output_list;
	stack<string> main_stack;

	for (int i = 0; i < tokens.size(); i++)
	{
		if (try_parse_number(tokens[i]))
		{
			output_list.push_back(tokens[i]);
		}
		if (tokens[i] == "(")
		{
			amount_of_left_brackets++;
			main_stack.push(tokens[i]);
		}
		if (tokens[i] == ")")
		{
			amount_of_right_brackets++;
			if (amount_of_right_brackets > amount_of_left_brackets) {
				throw Line_error("Not enought '(' brackets\n");
			}
			while (!main_stack.empty() && main_stack.top() != "(")
			{
				output_list.push_back(main_stack.top());
				main_stack.pop();
			}
			main_stack.pop();
		}
		if (is_operator(tokens[i]))
		{
			while (!main_stack.empty() && priority(main_stack.top()) >= priority(tokens[i]))
			{
				output_list.push_back(main_stack.top());
				main_stack.pop();
			}
			main_stack.push(tokens[i]);
		}
		if (!is_operator(tokens[i]) && !try_parse_number(tokens[i]) && tokens[i] != "" && tokens[i] != "(" && tokens[i] != ")") {
			throw Line_error("Unknown variable or function\n");
		}

	}
	//оставшиеся
	while (!main_stack.empty())
	{
		output_list.push_back(main_stack.top());
		main_stack.pop();
	}
	for (int i = 0; i < output_list.size(); i++) {
		if (output_list[i] == "(")
			throw Line_error("Not enought ')' brackets\n");
	}

	this->notation = output_list;
}


void Reverse_polish_notation::print_notation()
{
	if (!this->notation.empty()) {
		for (auto ch : notation) {
			cout << ch << " ";
		}
	}


}
