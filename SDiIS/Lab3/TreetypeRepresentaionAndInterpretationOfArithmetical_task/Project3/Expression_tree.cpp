#include "Expression_tree.h"


bool try_parse_number(string symbol)
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

Expression_tree_node* Expression_tree::parse(vector<string>& expression) 
{
	if (expression.size() == 0) {
		throw Line_error("More operators or operands required\n");
	}

	if (expression.size() >= 3 && is_operator(expression[expression.size()-1]) 
	&& try_parse_number(expression[expression.size() - 2]) 
	&& try_parse_number(expression[expression.size() - 3])) {
		Expression_tree_sign_node * expression_tree_sign_node = new Expression_tree_sign_node();
		expression_tree_sign_node->sign = expression.back();
		expression.pop_back();
		Expression_tree_num_node* expression_tree_right_son = new Expression_tree_num_node();
		expression_tree_sign_node->right_num = expression_tree_right_son;
		expression_tree_right_son->is_leaf = true;
		expression_tree_right_son->value = stoi(expression.back());
		expression.pop_back();
		Expression_tree_num_node* expression_tree_left_son = new Expression_tree_num_node();
		expression_tree_sign_node->left_num = expression_tree_left_son;
		expression_tree_left_son->is_leaf = true;
		expression_tree_left_son->value = stoi(expression.back());
		expression.pop_back();
		return expression_tree_sign_node;
	}
	else {
		Expression_tree_node* expression_tree_node = new Expression_tree_node();

		if (is_operator(expression.back())) {
			expression_tree_node->sign = expression.back();
		}
		else {
			expression_tree_node->is_leaf = true;
			expression_tree_node->value = stoi(expression.back());
			expression.pop_back();
			return expression_tree_node;
		}
		expression.pop_back();
		expression_tree_node->right = parse(expression);
		expression_tree_node->left = parse(expression);
		return expression_tree_node;
	}


}

int Expression_tree::compute(Expression_tree_node* node) throw (Math_error)
{
	if (node->is_leaf) {
		return node->value;
	}
	int left_value;
	int right_value;
	if (node->left)
		left_value = compute(node->left);
	else
		left_value = compute(node->left_num);
	if(node->right)
		right_value = compute(node->right);
	else
		right_value = compute(node->right_num);

	if (node->sign == "+") {
		return left_value + right_value;
	}
	else if (node->sign == "-") {
		return left_value - right_value;
	}
	else if (node->sign == "*") {
		return left_value * right_value;
	}
	else if (node->sign == "/") {
		if (right_value == 0)
			throw Math_error("Can't divide by zero\n");
		return left_value / right_value;
	}
	else if (node->sign == "^") {
		return pow(left_value, right_value);
	}
}

void Expression_tree::del_tree(Expression_tree_node* root)
{
	if (root)
	{
		del_tree(root->left);
		del_tree(root->right);
		delete root;
	}
}


int Expression_tree::compute_value()
{
	return compute(root);
}

void Expression_tree::build_tree(string line)
{
	Reverse_polish_notation notation;
	notation.make_notation(line);
	vector <string>expression = notation.get_notation();
	this->root = parse(expression);
}

void Expression_tree::print(Expression_tree_node* root, int level)
{
	if (!root)
		return;
	else {
		print(root->right, ++level);
		print(root->right_num, ++level);
		for (int i = 0; i < level; i++) cout << "     ";
		if (root->is_leaf)
			cout << root->value << endl;
		else
			cout << root->sign << endl;
		level--;
	}
	print(root->left, ++level);
	level--;
	print(root->left_num, ++level);
}

void Expression_tree::delete_tree()
{
	del_tree(root);
}

