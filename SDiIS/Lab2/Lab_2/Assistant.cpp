#include "Assistant.h"

//Assistant::Assistant(string name, int age, int course, string degree, double mid_mark, int salary, string subject, int year_of_service) :Student(name,age,course,mid_mark), Teacher(name, age, salary, year_of_service,subject,degree)
Assistant::Assistant(string name, int age, int course, string degree, double mid_mark, int salary, string subject, int year_of_service) :Student(course, mid_mark), Teacher(degree, salary, subject, year_of_service)
{
	this->name = name;
	this->age = age;
}

void Assistant::print()
{
	cout << "Object of Assistant class: \n   Name: " << this->name << "\n   Age: " << this->age << "\n   Course: " << this->course_of_study << "\n   Degree " << this->degree << "\n   Salary: " << this->salary << "\n   Middle mark: " << this->mid_mark << "\n   Subject: " << this->subject << endl;
}
