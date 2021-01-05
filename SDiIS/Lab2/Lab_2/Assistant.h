#pragma once
#include "Teacher.h"
#include "Student.h"

class Assistant : public Teacher,  public Student {
public:
	Assistant(string name, int age, int course, string degree, double mid_mark, int salary, string subject, int year_of_service);
	void print();
};