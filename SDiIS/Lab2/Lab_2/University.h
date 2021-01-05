#include <iostream>
using namespace std;


namespace university {

	class Person
	{
	protected:
		string name;
		int age;

	public:
		void set_name(string name);
		void set_age(int age);
		string get_name();
		int get_age();
		virtual void print() = 0;
	};

	class Employee :virtual protected Person
	{
	protected:
		int year_of_service;
		int salary;

	public:
		Employee() {}
		Employee(int salary, int year_of_service);
		Employee(string name, int age, int salary, int year_of_service);
		Person::get_age;
		Person::get_name;
		Person::set_name;
		Person::set_age;
		void set_year_of_service(int year_of_service);
		void set_salary(int salary);
		int get_year_of_service();
		int get_salary();
		void print();
	};

	class Teacher :virtual protected Employee
	{
	protected:
		string subject;
		string degree;
	public:
		Teacher(string degree, int salary, string subject, int year_of_service);
		Teacher(string name, int age, int salary, int year_of_service, string subject, string degree);
		void set_subject(string subject);
		void set_degree(string degree);
		string get_subject();
		string get_degree();
		void print();
	};

	class Administrator :private Employee {
		string adimnisistrator_role;
	public:
		Administrator(string name, int age, string admin_role, int salary, int year_of_service);
		void set_administrator_role(string admins_role);
		string get_administrator_role();
		void print();
	};

	class Student :virtual public Person
	{
	protected:
		double mid_mark;
		int course_of_study;
	public:
		Student(int course, double mid_mark);
		Student(string name, int age, int course, double mid_mark);
		void set_mid_mark(double mid_mark);
		void set_course(int course);
		double get_mid_mark();
		int get_course();
		void print();
	};

	class Assistant :virtual public Teacher,virtual public Student {
	public:
		Assistant(string name, int age, int course, string degree, double mid_mark, int salary, string subject, int year_of_service);
		void print();
	};

	class Professor :public Teacher {
		string publication;
	public:
		Professor(string name, int age, int salary, string degree, string subject, int year_of_service, string publication);
		void print();
	};
}
