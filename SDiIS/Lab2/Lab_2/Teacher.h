#pragma once

#include "Emoleyee.h"

using namespace std;

class Teacher :virtual public Employee
{
protected:
	string subject;
	string degree;
public:
	Teacher();
	Teacher(string degree, int salary, string subject, int year_of_service);
	Teacher(string name, int age, int salary, int year_of_service, string subject, string degree);
	void set_subject(string subject);
	void set_degree(string degree);
	string get_subject();
	string get_degree();
	void print();
};
