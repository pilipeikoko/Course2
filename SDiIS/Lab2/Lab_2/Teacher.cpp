#include "Teacher.h"

Teacher::Teacher() {
	
}

Teacher::Teacher(string degree, int salary, string subject, int year_of_service) :Employee()
{
	this->salary = salary;
	this->year_of_service = year_of_service;
	this->degree = degree;
	this->subject = subject;
}

Teacher::Teacher(string name, int age, int salary, int year_of_service, string subject, string degree) :Employee(name, age, salary, year_of_service)
{
	this->subject = subject;
	this->degree = degree;
}

void Teacher::set_subject(string subject)
{
	this->subject = subject;
}

void Teacher::set_degree(string degree)
{
	this->degree = degree;
}

string Teacher::get_subject()
{
	return subject;
}

string Teacher::get_degree()
{
	return degree;
}

void Teacher::print()
{
	cout << "Object of Assistant class: \n   Name: " << this->name << "\n   Age: " << this->age << "\n   Degree " << this->degree << "\n   Salary: " << this->salary << "\n   Subject: " << this->subject << "\n   Year of service: " << this->year_of_service << endl;
}