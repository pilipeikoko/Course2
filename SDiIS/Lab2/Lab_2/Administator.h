#pragma once
#include "Emoleyee.h"

class Administrator :private Employee {
	string adimnisistrator_role;
public:
	Administrator(string name, int age, string admin_role, int salary, int year_of_service);
	void set_administrator_role(string admins_role);
	string get_administrator_role();
	void print();
};