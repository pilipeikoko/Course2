#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Employee :virtual protected Person
{
protected:
	int year_of_service;
	int salary;

public:
	Employee();
	Employee(int salary, int year_of_service);
	Employee(string name, int age, int salary, int year_of_service);
	using Person::get_age;
	using Person::get_name;
	using Person::set_name;
	using Person::set_age;
	void set_year_of_service(int year_of_service);
	void set_salary(int salary);
	int get_year_of_service();
	int get_salary();
	void print();
};