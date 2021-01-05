#include "Assistant.h"
#include "Professor.h"
#include "Administator.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace scientist;

int main() {
	ifstream fin("input.txt");
	string name, subject, degree, publication,admin_role;
	int age, year_of_service,salary, course;
	double mid_mark;
	fin >> name >> age >> salary >> year_of_service;
	Employee obj_Employee(name, age, salary, year_of_service);
	fin >> name >> age >> salary >> year_of_service >> subject >> degree;
	Teacher obj_Teacher(name, age, salary, year_of_service, subject, degree);
	fin >> name >> age >> admin_role >> salary >> year_of_service;
	Administrator obj_Administrator(name, age, admin_role, salary, year_of_service);
	fin >> name >> age >> course >> mid_mark;
	Student obj_Student(name, age, course, mid_mark);
	fin >> name >> age >> course >> degree >>mid_mark>> salary >> subject >> year_of_service;
	Assistant obj_Assistant(name, age, course, degree, mid_mark, salary, subject, year_of_service);
	fin >> name >> age >> salary >> degree >> subject >> year_of_service >> publication;
	Professor obj_Professor(name, age, salary, degree, subject, year_of_service, publication);
	obj_Employee.print();
	obj_Teacher.print();
	obj_Administrator.print();
	obj_Student.print();
	obj_Assistant.print();
	obj_Professor.print();
	//empl student
}