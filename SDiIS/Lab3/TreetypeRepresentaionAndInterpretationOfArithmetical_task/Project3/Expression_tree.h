#pragma once
#include <iostream>
#include <string>
#include "Users_functions.h"
#include "Reverse_polish_notation.h"
#include <vector>
#include "Line_error.h"
#include "Math_error.h"
using namespace std;

class Expression_tree_num_node;

class Expression_tree_node
{
	Expression_tree_node* left, * right;
protected:
	Expression_tree_num_node* left_num, * right_num;
	string sign;
	int value;
	bool is_leaf;

public:
	friend class Expression_tree;
};

class Expression_tree_num_node :protected Expression_tree_node {
	using Expression_tree_node::value;

public:
	friend class Expression_tree;
};

class Expression_tree_sign_node : protected Expression_tree_node {
	using Expression_tree_node::left_num; 
	using Expression_tree_node::right_num;
	using Expression_tree_node::sign;

public:
	friend class Expression_tree;
};




class Expression_tree
{
	Expression_tree_node* parse(vector<string>& expression);
	int compute(Expression_tree_node* node) throw (Math_error);
	void del_tree(Expression_tree_node* root);

public:
	Expression_tree_node* root;
	int compute_value();
	void build_tree(string line);
	void print(Expression_tree_node* root, int level = 0);
	void delete_tree();

};