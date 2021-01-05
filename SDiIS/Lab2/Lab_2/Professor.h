#pragma once
#include "Teacher.h"

using namespace std;
namespace scientist {
	class Professor :public Teacher {
		string publication;
	public:
		Professor(string name, int age, int salary, string degree, string subject, int year_of_service, string publication);
		void print();
	};
}