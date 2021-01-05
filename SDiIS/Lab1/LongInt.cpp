#include "LongInt.h"
using namespace std;

/// Default constructor
LongInt::LongInt() {
	minus = 0;
}


/// Constructor that sets the number
LongInt::LongInt(const int num)
{
	*this = num;
}

/*!
* \return LongInt variable that equals the sum of two LongInt variables
*/
LongInt LongInt::operator+(const LongInt& other)
{
	if (this->minus && !other.minus)
	{
		LongInt z1 = *this, z2 = other;
		z1.minus = 0;
		return z2 - z1;
	}
	else if (!this->minus && other.minus)
	{
		LongInt z1 = *this, z2 = other;
		z2.minus = 0;
		return z1 - z2;
	}
	LongInt temp;
	if (this->minus && other.minus) temp.minus = 1;
	vector<int> a = this->number, b = other.number;
	int lenth1 = a.size();
	int lenth2 = b.size();
	for (int i = lenth1; i < lenth2; i++)
		a.insert(a.begin(), 0);
	for (int i = lenth2; i < lenth1; i++)
		b.insert(b.begin(), 0);
	if (lenth1 < lenth2) lenth1 = lenth2;
	int additional_term = 0;
	while (lenth1)
	{
		lenth1--;
		int sum = a[lenth1] + b[lenth1] + additional_term;
		temp.number.push_back(sum % 10);
		additional_term = sum / 10;
	}
	if (additional_term != 0) temp.number.push_back(additional_term);
	reverse(temp.number.begin(), temp.number.end());
	return temp;
}

/*! 
* \return LongInt variable equals the sum of LongInt and int variables
*/ 
LongInt LongInt::operator+(int number) {
	LongInt temp;
	temp = number;
	return *this + temp;
}

/*! 
* \return Assigns to a LongInt variable the sum of itself and other LongInt variable
*/
LongInt LongInt::operator+=(const LongInt& other) {
	return *this = *this + other;
}


/*!
* Assigns to a LongInt variable the sum of itself and int variable
*/
LongInt LongInt::operator+=(int number) {
	return *this = *this + number;
}

/*!
* \return the subtraction of LongInt by LongInt variable
*/
LongInt LongInt::operator-(const LongInt& other)
{
	LongInt temp;
	vector<int> a = this->number, b = other.number;
	int lenth1 = a.size();
	int lenth2 = b.size();
	for (int i = lenth1; i < lenth2; i++)
		a.insert(a.begin(), 0);
	for (int i = lenth2; i < lenth1; i++)
		b.insert(b.begin(), 0);
	if (lenth1 < lenth2) lenth1 = lenth2;

	if (this->minus == 0 && other.minus == 0)
	{
		int KEY = 0;
		for (int i = 0; i < lenth1; i++) {
			if (a[i] > b[i]) {
				KEY = 1;
				break;
			}
			else if (b[i] > a[i]) {
				KEY = 2;
				break;
			}
		}
		if (KEY == 0) {
			temp.number.push_back(0);
			return temp;
		}
		if (KEY == 2) {
			temp.minus = 1;
			auto d = b;
			b = a;
			a = d;
		}
		while (lenth1) {
			lenth1--;
			int razn = a[lenth1] - b[lenth1];
			if (razn >= 0) temp.number.push_back(razn);
			else {
				int i = lenth1;
				while (i) {
					i--;
					if (a[i] > 0) {
						a[i]--;
						break;
					}
					else a[i] = 9;
				}
				razn += 10;
				temp.number.push_back(razn);
			}
		}
		reverse(temp.number.begin(), temp.number.end());
	}
	else if (this->minus == 0 && other.minus == 1) {
		LongInt z1 = *this, z2 = other;
		z2.minus = 0;
		return z1 + z2;
	}
	else if (this->minus == 1 && other.minus == 0) {
		LongInt z1 = *this, z2 = other;
		z2.minus = 1;
		return z1 + z2;
	}
	else if (this->minus == 1 && other.minus == 1) {
		LongInt z1 = *this, z2 = other;
		z2.minus = 0;
		z1.minus = 0;
		return z2 - z1;
	}
	while ((int)temp.number.size() > 0 && temp.number[0] == 0)
		temp.number.erase(temp.number.begin());
	if ((int)temp.number.size() == 0) temp.number.push_back(0);
	return temp;
}

/*!
* \return the subtraction of LongInt by int variable
*/
LongInt LongInt::operator-(int number)
{
	LongInt temp;
	temp = number;
	return *this - temp;
}

/*!
* Assigns to a LongInt variable the subtraction of itself by other LongInt variable
*/
LongInt LongInt::operator-=(const LongInt& other)
{
	return *this = *this - other;
}

/*!
* Assigns to a LongInt variable the subtraction of itself by int variable
*/
LongInt LongInt::operator-=(int number)
{
	return *this = *this - number;
}


/*!
* Returns the multiplication of LongInt and LongInt variable
*/
LongInt LongInt::operator*(const LongInt& other) {
	LongInt temp;
	LongInt z1 = *this, z2 = other;
	int lenth1 = z1.number.size();
	int lenth2 = z2.number.size();
	if (lenth1 < lenth2)
	{
		auto additional_term = z2;
		z2 = z1;
		z1 = additional_term;
		lenth1 = z1.number.size();
		lenth2 = z2.number.size();
	}
	int additional_term = 0;
	int number_zeros = 0;
	for (int j = lenth2 - 1; j >= 0; j--)
	{
		LongInt sum;
		for (int i = lenth1 - 1; i >= 0; i--)
		{
			int composition = z1.number[i] * z2.number[j] + additional_term;
			sum.number.push_back(composition % 10);
			additional_term = composition / 10;
		}
		if (additional_term > 0) sum.number.push_back(additional_term);
		reverse(sum.number.begin(), sum.number.end());
		for (int i = 0; i < number_zeros; i++)
			sum.number.push_back(0);
		number_zeros++;
		temp = temp + sum;
	}
	if ((!z1.minus && z2.minus) || (z1.minus & !z2.minus)) {
		temp.minus = true;
	}
	return temp;
}

/*! 
* \return the multiplication of LongInt and int variable
*/
LongInt LongInt::operator*(const int number)
{
	LongInt temp;
	temp = number;
	return *this * temp;
}

/*! 
* \return The multiplication of LongInt variable by other LongInt variable
*/
LongInt LongInt::operator*=(const LongInt& other)
{
	return *this = *this * other;
}


LongInt LongInt::operator*=(const int number)
{
	return *this = *this * number;
}


/*!
* \return The division of LongInt by int variable
*/
LongInt LongInt::operator/(const int& other) {
	LongInt temp = other;
	return *this / temp;
}



LongInt LongInt::operator/=(const int& other)
{
	return *this = *this / other;
}


LongInt LongInt::operator/(LongInt& other) {
	bool minus = 0;
	LongInt z1 = *this, z2 = other, temp;
	if ((z1.minus == 1 && z2.minus == 0) || (z1.minus == 0 && z2.minus == 1)) minus = 1;
	z1.minus = 0;
	z2.minus = 0;
	LongInt zero;
	zero.number.push_back(0);
	if (z2 == zero) {
		cout << "Can't divide by zero!\n";
		exit(0);
	}
	if (z1 < z2)
	{
		temp = 0;
		return temp;
	}
	LongInt one;
	one.number.push_back(1);
	LongInt l = one;
	LongInt r = z1;
	while (r - l > one)
	{
		LongInt mid = division_by_two(r + l);
		if (mid * z2 < z1) l = mid;
		else r = mid;
	}
	if (r * z2 == z1) temp = r;
	else temp = l;
	if (minus == 1) temp.minus = 1;
	return temp;
}


/*!
* \return A LongInt variable divided by other LongInt variable
*/
LongInt LongInt::operator/=(LongInt& other)
{
	return *this = *this / other;
}


/*!
* \return  Increased LongInt variable by one after the action(postfix notation)
*/
LongInt LongInt::operator++(int notused) {
	LongInt new_object;
	new_object = *this;
	if (number.size() == 0) {
		cout << "Mistake! Uninitialized variable!";
		exit(1);
	}
	if (!minus) {
		if (number.size() == 1 && number[0] < 9) {
			number[0]++;
			return new_object;
		}
		increment_plus(number);
	}
	else {
		if (number.size() == 1 && number[0] < 9) {
			number[0]--;
			if (!number[0])minus = false;
			return new_object;
		}
		increment_minus(number);
	}
	return new_object;
}


/*!
* \return Increased LongInt variable by one before the action(prefix notation)
*/
LongInt LongInt::operator++() {
	if (number.size() == 0) {
		cout << "Mistake! Uninitialized variable!";
		exit(1);
	}
	if (!minus) {
		if (number.size() == 1 && number[0] < 9) {
			number[0]++;
			return *this;
		}
		increment_plus(number);
	}
	else {
		if (number.size() == 1 && number[0] < 9) {
			number[0]--;
			if (!number[0])minus = false;
			return *this;
		}
		increment_minus(number);
	}
	return *this;
}


/*!
* \return Decreased LongInt variable by one after the action(postfix notation)
*/
LongInt LongInt::operator--(int notused) {
	LongInt new_object;
	new_object = *this;
	if (number.size() == 0) {
		cout << "Mistake! Uninitialized variable!";
		exit(1);
	}
	if (minus) {
		if (number.size() == 1 && number[0] < 9) {
			number[0]++;
			return new_object;
		}
		increment_plus(number);
	}
	else {
		if (number.size() == 1 && number[0] < 9) {
			if (number[0] == 0) {
				number[0] = 1;
				minus = true;
				return new_object;
			}
			number[0]--;
			return new_object;
		}
		increment_minus(number);
	}
	return new_object;
}


/*!
* \return Decreased LongInt variable by one before the action(prefix notation)
*/
LongInt LongInt::operator--() {
	if (number.size() == 0) {
		cout << "Mistake! Uninitialized variable!";
		exit(1);
	}
	if (minus) {
		if (number.size() == 1 && number[0] < 9) {
			number[0]++;
			return *this;
		}
		increment_plus(number);
	}
	else {
		if (number.size() == 1 && number[0] < 9) {
			if (number[0] == 0) {
				number[0] = 1;
				minus = true;
				return *this;
			}
			number[0]--;
			return *this;
		}
		increment_minus(number);
	}
	return *this;
}

LongInt& LongInt::operator=(int& value)
{
	number.clear();
	if (value == 0) {
		number.push_back(0);
		return *this;
	}
	if (value < 0)minus = true;
	value = abs(value);
	while (value) { 
		int curr = value % 10;
		value /= 10;
		number.insert(number.begin(), curr);
	}
	return *this;
}


LongInt& LongInt::operator=(const int& value)
{
	number.clear();
	if (value < 0)minus = true;
	int new_value = abs(value);
	if (new_value == 0) {
		number.push_back(0);
		return *this;
	}
	while (new_value) {
		int curr = new_value % 10;
		new_value /= 10;
		number.insert(number.begin(), curr);
	}
	return *this;
}

LongInt& LongInt::operator=(LongInt obj)
{
	number.clear();
	minus = obj.minus;
	for (auto ch : obj.number)
		number.push_back(ch);
	return *this;
}


/*! 
* \return true if two LongInt variables are equal, else returns false
*/
bool LongInt::operator==(LongInt& other)
{
	if (this->minus != other.minus)
		return false;
	if (this->number.size() == other.number.size()) {
		for (register int i = 0; i < this->number.size(); i++) {
			if (this->number[i] != other.number[i])
				return false;
		}
		return true;
	}
	else return false;
}


/*!
* \return true if LongInt and int variables are equal, else false
*/
bool LongInt::operator==(int number)
{
	LongInt temp;
	temp = number;
	return *this == temp;
}


/*!
* \return true if left LongInt virable is lesser than right LongInt variable,else false
*/
bool LongInt::operator<(const LongInt& other)
{
	if (minus && !other.minus) return true;
	if (!minus && other.minus) return false;
	int size1 = this->number.size();
	int size2 = other.number.size();
	bool KEY = true;
	if (minus)KEY = false;//if both numbers are negative, changing key's value
	if (size1 > size2) {
		return !KEY;
	}
	else if (size2 > size1) {
		return KEY;
	}
	for (int i = 0; i < size1; i++) {
		if (this->number[i] > other.number[i]) {
			return !KEY;
		}
		else if (this->number[i] < other.number[i]) {
			return KEY;
		}
	}
	return false;
}


/*!
* \return true if left LongInt virable is lesser than right const int variable, else false
*/
bool LongInt::operator<(const int& number)
{
	LongInt temp;
	temp = number;
	return *this < temp;
}


/*!
* \return true if left LongInt virable is lesser or equals right LongInt variable, else false
*/
bool LongInt::operator<=(LongInt& other)
{
	return *this == other || *this < other;
}


/*!
* \return true if left LongInt virable is lesser or equals right const int variable, else false
*/
bool LongInt::operator<=(const int& number)
{
	LongInt temp;
	temp = number;
	return *this <= temp;
}


/*!
*\return true if left LongInt virable is more than right const LongInt variable, else false
*/
bool LongInt::operator>(const LongInt& other)
{
	if (minus && !other.minus) return false;
	if (!minus && other.minus) return true;
	int size1 = number.size();
	int size2 = other.number.size();
	bool KEY = true;
	if (minus) KEY = false;//if both numbers are negative, changing key's value
	if (size1 > size2) {
		return KEY;
	}
	else if (size2 > size1) {
		return !KEY;
	}
	for (int i = 0; i < size1; i++) {
		if (number[i] > other.number[i]) {
			return KEY;
		}
		else if (number[i] < other.number[i]) {
			return !KEY;
		}
	}
	return false;
}


/*!
* \return true if left LongInt virable is more than right const int variable else false
*/
bool LongInt::operator>(const int& number)
{
	LongInt temp;
	temp = number;
	return *this > temp;
}


/*!
* \return true if left LongInt virable is more or equals right const LongInt variable else false
*/
bool LongInt::operator>=(LongInt& other)
{
	return *this == other || *this > other;
}


/*!
* \return true if left LongInt virable is more or equals right const int variable, else false
*/ 
bool LongInt::operator>=(const int& number)
{
	LongInt temp;
	temp = number;
	return *this >= temp;
}

ostream& operator<<(ostream& out, LongInt obj)
{
	if (obj.minus)cout << "-";
	for (auto ch : obj.number)
		cout << ch;
	return out;
}

istream& operator>>(istream& in, LongInt& obj)
{
	string num_str;
	cin >> num_str;
	if (num_str[0] == '-') {
		obj.minus = true;
		for (register int i = 1; i < num_str.size(); i++)
			obj.number.push_back(num_str[i] - '0');
	}
	else {
		for (auto ch : num_str)
			obj.number.push_back(ch - '0');
	}
	return in;
}



/*!
* \return Decreased number in vector's type by one
*/
void increment_plus(vector<int>& obj) {
	int i = obj.size() - 1;
	while (i >= 0) {
		if (++obj[i] == 10) {
			obj[i] = 0;
			i--;
		}
		else break;
	}
	if (obj[0] == 0) {
		obj.insert(obj.begin(), 1);
	}
}


/*!
* \return Increased number in vector's type by one
*/
void increment_minus(vector<int>& obj) {
	int i = obj.size() - 1;
	while (i >= 0) {
		if (--obj[i] == -1) {
			obj[i] = 9;
			i--;
		}
		else break;
	}
	if (obj[0] == 0) {
		obj.erase(obj.begin());
	}
}


/*!
* \return LongInt variable divided by two 
*/
LongInt division_by_two(LongInt z)
{
	LongInt temp;
	int ost = 0;
	for (int i = 0; i < z.number.size(); i++)
	{
		if (z.number[i] == 0 && ost == 0) temp.number.push_back(0);
		else {
			if (ost < 2) {
				ost = ost * 10 + z.number[i];
			}
			temp.number.push_back(ost / 2);
			ost %= 2;
		}
	}
	while (!temp.number.empty() && *temp.number.begin() == 0)
		temp.number.erase(temp.number.begin());
	if (temp.number.empty())
		temp.number.push_back(0);
	return temp;
}