#include "Administator.h"

Administrator::Administrator(string name, int age, string admin_role, int salary, int year_of_service) : Employee(name, age, salary, year_of_service)
{
	this->adimnisistrator_role = admin_role;
}

void Administrator::set_administrator_role(string admins_role)
{
	this->adimnisistrator_role = admins_role;
}

string Administrator::get_administrator_role()
{
	return this->adimnisistrator_role;
}

void Administrator::print()
{
	cout << "Object of Administrator class: \n   Name: " << this->name << "\n   Age: " << this->age << "\n   Administrator role: " << this->adimnisistrator_role << "\n   Salary: " << this->salary << "\n   Year of service: " << this->year_of_service << endl;
}

