#include "Emoleyee.h"

Employee::Employee()
{
	this->age = NULL;
	this->name = "";
	this->salary = NULL;
	this->year_of_service = NULL;
}

Employee::Employee(int salary, int year_of_service)
{
	this->salary = salary;
	this->year_of_service = year_of_service;
}

Employee::Employee(string name, int age, int salary, int year_of_service)
{
	this->name = name;
	this->age = age;
	this->year_of_service = year_of_service;
	this->salary = salary;
}

void Employee::set_year_of_service(int year_of_service)
{
	this->year_of_service = year_of_service;
}

void Employee::set_salary(int salary)
{
	this->salary = salary;
}

int Employee::get_year_of_service()
{
	return year_of_service;
}

int Employee::get_salary()
{
	return salary;
}

void Employee::print() {
	cout << "Object of Employee class:\n   Name: " << this->name << "\n   Age: " << this->age << "\n   Salary: " << this->salary << "\n   Year of service: " << this->year_of_service << endl;
}
