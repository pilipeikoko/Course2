#include "Person.h"

Person::Person() {
	this->age = NULL;
	this->name = "";
}

void Person::set_name(string name)
{
	this->name = name;
}

void Person::set_age(int age)
{
	this->age = age;
}

string Person::get_name()
{
	return name;
}

int Person::get_age()
{
	return age;
}

