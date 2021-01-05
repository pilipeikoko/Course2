#include "Professor.h"
using namespace scientist;

Professor::Professor(string name, int age, int salary, string degree, string subject, int year_of_service, string publication) 
{
	this->name = name;
	this->age = age;
	this->salary = salary;
	this->degree = degree;
	this->subject = subject;
	this->year_of_service = year_of_service;
	this->publication = publication;
}

void Professor::print()
{
	cout << "Object of Professor class: \n   Name: " << this->name << "\n   Age: " << this->age << "\n   Degree " << this->degree << "\n   Salary: " << this->salary << "\n   Year of service: " << this->year_of_service << "\n   Subject: " << this->subject << "\n   Publication: " << this->publication << endl;
}