#include "University.h"

using namespace university;

//class Person
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

//class Employee
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
	cout << "Object of Employee class:\nName: " << this->name << "\nAge: " << this->age << "\nSalary: " << this->salary << "\nYear of service: " << this->year_of_service << endl;
}
//class teacher
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
	cout << "Object of Assistant class: \n Name: " << this->name << "\nAge: " << this->age << "\nDegree " << this->degree << "\nSalary: " << this->salary << "\nSubject: " << this->subject << "\nYear of service: " << this->year_of_service << endl;
}


//class Administrator
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
	cout << "Object of Administrator class: \n Name: " << this->name << "\nAge: " << this->age << "\nAdministrator role: " << this->adimnisistrator_role << "\nSalary: " << this->salary << "\nYear of service: " << this->year_of_service << endl;
}

//class Student

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
	cout << "Object of Student class: \nName: " << name<< "\nAge: " << age << "\nCourse: " << this->course_of_study << "\n Middle mark: " << this->mid_mark << endl;
}


//class Assistant

Assistant::Assistant(string name, int age, int course, string degree, double mid_mark, int salary, string subject, int year_of_service) :Student(course, mid_mark), Teacher(degree, salary, subject, year_of_service)
{
	this->name = name;
	this->age = age;
}

void Assistant::print()
{
	cout << "Object of Assistant class: \n Name: " << this->name << "\nAge: " << this->age << "\nCourse: " << this->course_of_study << "\nDegree " << this->degree << "\nSalary: " << this->salary << "\nMiddle mark: " << this->mid_mark << "\nSubject: " << this->subject << endl;
}

//class Professor

Professor::Professor(string name, int age, int salary, string degree, string subject, int year_of_service, string publication) :Teacher(name, age, salary, year_of_service, subject, degree)
{
	this->publication = publication;
}

void Professor::print()
{
	cout << "Object of Professor class: \n Name: " << this->name << "\nAge: " << this->age << "\nDegree " << this->degree << "\nSalary: " << this->salary << "\nYear of service: " << this->year_of_service << "\nSubject: " << this->subject << "\nPublication: " << this->publication << endl;
}

