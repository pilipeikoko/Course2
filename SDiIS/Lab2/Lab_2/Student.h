#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Student :virtual public Person
{
protected:
	double mid_mark;
	int course_of_study;
public:
	Student(int course, double mid_mark);
	Student(string name, int age, int course, double mid_mark);
	void set_mid_mark(double mid_mark);
	void set_course(int course);
	double get_mid_mark();
	int get_course();
	void print();
};
