#pragma once
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

class LongInt {
	vector<int> number;
	bool minus;
public:
	/// Default constructor
	LongInt();
	/// Constructor that sets the number
	LongInt(const int num);

	/// Returns the sum of two LongInt variables
	LongInt operator+(const LongInt& other);
	/// Returns the sum of LongInt and int variables
	LongInt operator+(int number);
	/// Assigns to a LongInt variable the sum of itself and other LongInt variable
	LongInt operator+=(const LongInt& other);
	/// Assigns to a LongInt variable the sum of itself and int variable
	LongInt operator+=(int number);

	/// Returns the subtraction of LongInt by LongInt variable
	LongInt operator-(const LongInt& other);
	/// Returns the subtraction of LongInt by int variable
	LongInt operator-(int number);
	/// Assigns to a LongInt variable the subtraction of itself by other LongInt variable
	LongInt operator-=(const LongInt& other);
	/// Assigns to a LongInt variable the subtraction of itself by int variable
	LongInt operator-=(int number);

	/// Returns the multiplication of LongInt and LongInt variable
	LongInt operator*(const LongInt& other);
	/// Returns the multiplication of LongInt and int variable
	LongInt operator*(const int number);
	/// Assigns to a LongInt variable the multiplication of itself and other LongInt variable
	LongInt operator*=(const LongInt& other);
	///Assigns to a LongInt variable the multiplication of itself and int variable
	LongInt operator*=(const int number);

	/// Returns the division of LongInt by int variable
	LongInt operator/(const int& other);
	/// Assigns to a LongInt variable the division of itself by int variable
	LongInt operator/=(const int& other);
	/// Returns the division of LongInt by LongInt variable
	LongInt operator/(LongInt& other);
	/// Assigns to a LongInt variable the division of itself by other LongInt variable
	LongInt operator/=(LongInt& other);

	/// Increases LongInt variable by one after the action(postfix notation)
	LongInt operator++(int notused);
	/// Increases LongInt variable by one before the action(prefix notation)
	LongInt operator++();
	/// Decreases LongInt variable by one after the action(postfix notation)
	LongInt operator--(int notused);
	/// Decreases LongInt variable by one before the action(prefix notation)
	LongInt operator--();

	/// Assigs LongInt virable int's value
	LongInt& operator=(int& value);
	/// Assigs LongInt virable const int's value
	LongInt& operator=(const int& value);
	/// Assigs LongInt virable LongInt value
	LongInt& operator=(LongInt obj);

	/// Returns true if two LongInt variables are equal, else returns false
	bool operator==(LongInt& other);
	/// Returns true if LongInt and int variables are equal, else returns false
	bool operator==(int number);
	/// Returns true if left LongInt virable is lesser than right LongInt variable
	bool operator<(const LongInt& other);
	/// Returns true if left LongInt virable is lesser than right const int variable
	bool operator<(const int& number);
	/// Returns true if left LongInt virable is lesser or equals right LongInt variable
	bool operator<=(LongInt& other);
	/// Returns true if left LongInt virable is lesser or equals right const int variable
	bool operator<=(const int& number);
	/// Returns true if left LongInt virable is more than right const LongInt variable
	bool operator>(const LongInt& other);
	/// Returns true if left LongInt virable is more than right const int variable
	bool operator>(const int& number);
	/// Returns true if left LongInt virable is more or equals right const LongInt variable
	bool operator>=(LongInt& other);
	/// Returns true if left LongInt virable is more or equals right const int variable
	bool operator>=(const int& number);

	/// Input stream
	friend ostream& operator<<(ostream& out, LongInt obj);
	/// Output stream
	friend istream& operator>>(istream& in, LongInt& obj);

	/// Sub-function, returns LongInt variable divided by two
	friend LongInt division_by_two(LongInt z);

};

/// Increases the number in vector's type by one
void increment_plus(vector<int>& obj);
/// Decreases the number in vector's type by one
void increment_minus(vector<int>& obj);