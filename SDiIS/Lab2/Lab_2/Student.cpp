#include "Student.h"

Student::Student(int course, double mid_mark)
{
	this->course_of_study = course;
	this->mid_mark = mid_mark;
}

Student::Student(string name, int age, int course, double mid_mark)
{
	this->name = name;
	this->age = age;
	this->mid_mark = mid_mark;
	this->course_of_study = course;
}

void Student::set_mid_mark(double mid_mark)
{
	this->mid_mark = mid_mark;
}

void Student::set_course(int course)
{
	this->course_of_study = course;
}

double Student::get_mid_mark()
{
	return mid_mark;
}

int Student::get_course()
{
	return course_of_study;
}

void Student::print()
{
	cout << "Object of Student class: \n   Name: " << name << "\n   Age: " << age << "\n   Course: " << this->course_of_study << "\n   Middle mark: " << this->mid_mark << endl;
}
