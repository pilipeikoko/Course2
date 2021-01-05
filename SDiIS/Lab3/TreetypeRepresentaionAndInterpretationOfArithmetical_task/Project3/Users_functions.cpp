#include "Users_functions.h" 

void Functions::replace_sin(string& line) throw (Line_error)
{
	Expression_tree tree;
	string expression = "";
	int assign_index;
	int result;

	while (line.find("sin") != -1) {
		assign_index = line.find("sin");
		int count_left_bracket = 0, count_right_bracket = 0;
		if (line[assign_index + 3] != '(')
			throw Line_error("'(' required");
		for (int i = assign_index + 3; i < line.length(); i++) {
			if (line[i] == '(') {
				count_left_bracket++;
				i++;
			}
			while (count_left_bracket != count_right_bracket)
			{
				expression += line[i];
				i++;
				if (line[i] == ')')
					count_right_bracket++;
				else if (line[i] == '(')
					count_left_bracket++;
			}
			break;
		}

		tree.build_tree(expression);

		result = tree.compute_value();
		result = sin(result);

		line.erase(assign_index, expression.length() + 5);
		line.insert(assign_index, to_string(result));
	}
}

void Functions::replace_cos(string& line) throw (Line_error)
{
	Expression_tree tree;
	string expression = "";
	int assign_index;
	int result;

	while (line.find("cos") != -1) {
		assign_index = line.find("cos");
		int count_left_bracket = 0, count_right_bracket = 0;
		if (line[assign_index + 3] != '(')
			throw Line_error("'(' required");
		for (int i = assign_index + 3; i < line.length(); i++) {
			if (line[i] == '(') {
				count_left_bracket++;
				i++;
			}
			while (count_left_bracket != count_right_bracket)
			{
				expression += line[i];
				i++;
				if (line[i] == ')')
					count_right_bracket++;
				else if (line[i] == '(')
					count_left_bracket++;
			}
			break;
		}
		tree.build_tree(expression);

		result = tree.compute_value();
		result = cos(result);

		line.erase(assign_index, expression.length() + 5);
		line.insert(assign_index, to_string(result));
	}
}

void Functions::replace_tg(string& line) throw (Line_error)
{
	Expression_tree tree;
	string expression = "";
	int assign_index;
	int result;

	while (line.find("tg") != -1) {
		assign_index = line.find("tg");
		int count_left_bracket = 0, count_right_bracket = 0;
		if (line[assign_index + 2] != '(')
			throw Line_error("'(' required");
		for (int i = assign_index + 2; i < line.length(); i++) {
			if (line[i] == '(') {
				count_left_bracket++;
				i++;
			}
			while (count_left_bracket != count_right_bracket)
			{
				expression += line[i];
				i++;
				if (line[i] == ')')
					count_right_bracket++;
				else if (line[i] == '(')
					count_left_bracket++;
			}
			break;
		}
		tree.build_tree(expression);

		result = tree.compute_value();
		result = tan(result);

		line.erase(assign_index, expression.length() + 4);
		line.insert(assign_index, to_string(result));
	}
}

void Functions::replace_ctg(string& line) throw (Line_error)
{
	Expression_tree tree;
	string expression = "";
	int assign_index;
	int result;

	while (line.find("ctg") != -1) {
		assign_index = line.find("ctg");
		int count_left_bracket = 0, count_right_bracket = 0;
		if (line[assign_index + 3] != '(')
			throw Line_error("'(' required");
		for (int i = assign_index + 3; i < line.length(); i++) {
			if (line[i] == '(') {
				count_left_bracket++;
				i++;
			}
			while (count_left_bracket != count_right_bracket)
			{
				expression += line[i];
				i++;
				if (line[i] == ')')
					count_right_bracket++;
				else if (line[i] == '(')
					count_left_bracket++;
			}
			break;
		}
		tree.build_tree(expression);

		result = tree.compute_value();
		result = 1 / (tan(result));

		line.erase(assign_index, expression.length() + 5);
		line.insert(assign_index, to_string(result));
	}
}

void Functions::replace_sqrt(string& line) throw (Line_error)
{
	Expression_tree tree;
	string expression = "";
	int assign_index;
	int result;

	while (line.find("sqrt") != -1) {
		assign_index = line.find("sqrt");
		int count_left_bracket = 0, count_right_bracket = 0;
		if (line[assign_index + 4] != '(')
			throw Line_error("'(' required");
		for (int i = assign_index + 4; i < line.length(); i++) {
			if (line[i] == '(') {
				count_left_bracket++;
				i++;
			}
			while (count_left_bracket != count_right_bracket)
			{
				expression += line[i];
				i++;
				if (line[i] == ')')
					count_right_bracket++;
				else if (line[i] == '(')
					count_left_bracket++;
			}
			break;
		}
		tree.build_tree(expression);

		result = tree.compute_value();
		result = sqrt(result);

		line.erase(assign_index, expression.length() + 6);
		line.insert(assign_index, to_string(result));
	}
}

void Functions::replace_log(string& line) throw (Line_error)
{
	Expression_tree tree;
	string expression = "";
	int assign_index;
	int result;

	while (line.find("log") != -1) {
		assign_index = line.find("log");
		int count_left_bracket = 0, count_right_bracket = 0;
		if (line[assign_index + 3] != '(')
			throw Line_error("'(' required");
		for (int i = assign_index + 3; i < line.length(); i++) {
			if (line[i] == '(') {
				count_left_bracket++;
				i++;
			}
			while (count_left_bracket != count_right_bracket)
			{
				expression += line[i];
				i++;
				if (line[i] == ')')
					count_right_bracket++;
				else if (line[i] == '(')
					count_left_bracket++;
			}
			break;
		}

		tree.build_tree(expression);

		result = tree.compute_value();
		result = log(result);

		line.erase(assign_index, expression.length() + 5);
		line.insert(assign_index, to_string(result));
	}
}

string Functions::function_processing(string& line)
{
	int assign_index;

	replace_sin(line);
	replace_cos(line);
	replace_ctg(line);
	replace_tg(line);
	replace_sqrt(line);
	replace_log(line);

	while (line.find("--") != -1) {
		assign_index = line.find("--");
		line.erase(assign_index, 2);
	}

	return line;
}

