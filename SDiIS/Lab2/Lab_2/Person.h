#pragma once
#include <iostream>

using namespace std;

class Person
{
protected:
	string name;
	int age;

public:
	Person();
	void set_name(string name);
	void set_age(int age);
	string get_name();
	int get_age();
	virtual void print() = 0;
};