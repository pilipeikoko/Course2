#include "CppUnitTest.h"
#include "../PPVIS_lab1/LongInt.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LongIntTest1
{
	TEST_CLASS(LongIntTest1)
	{
	public:

		TEST_METHOD(Test_LongInt_plus_LongInt)
		{
			LongInt a = 2, b = 3, c = 5;
			Assert::IsTrue(a + b == c);
		}
		TEST_METHOD(Test_LongInt_plus_int)
		{
			LongInt a = 2;
			int b = 2, c = 4;
			Assert::IsTrue(a + b == c);
		}
		TEST_METHOD(Test_LongInt_PlusEquals_LongInt)
		{
			LongInt a = 1000, b = 50, c = 1050;
			a += b;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_PlusEquals_int)
		{
			LongInt a = 33, c = 38;
			int b = 5;
			a += b;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_minus_LongInt)
		{
			LongInt a = 100, b = 2, c = 98;
			Assert::IsTrue(a - b == c);
		}
		TEST_METHOD(Test_LongInt_minus_int)
		{
			LongInt a = 1000;
			int b = 55, c = 945;
			Assert::IsTrue(a - b == c);
		}
		TEST_METHOD(Test_LongInt_MinusEquals_LongInt)
		{
			LongInt a = 22, b = 2, c = 20;
			a -= b;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_MinusEquals_int)
		{
			LongInt a = 10000;
			int b = 55, c = 9945;
			a -= b;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_multiply_LongInt)
		{
			LongInt a = 2, b = 3, c = 6;
			Assert::IsTrue(a * b == c);
		}
		TEST_METHOD(Test_LongInt_multiply_int)
		{
			LongInt a = 20004;
			int b = 2, c = 40008;
			Assert::IsTrue(a * b == c);
		}
		TEST_METHOD(Test_LongInt_MultiplyEquals_LongInt)
		{
			LongInt a = 333333333, b = 3, c = 999999999;
			a *= b;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_MultiplyEquals_int)
		{
			LongInt a = 2200, c = 8800;
			int b = 4;
			a *= b;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_divide_LongInt)
		{
			LongInt a = 100000, b = 2, c = 50000;
			Assert::IsTrue(a / b == c);
		}
		TEST_METHOD(Test_LongInt_divide_int)
		{
			LongInt a = 20004;
			int b = 2, c = 10002;
			Assert::IsTrue(a / b == c);
		}
		TEST_METHOD(Test_LongInt_DivideEquals_LongInt)
		{
			LongInt a = 22222, b = 2, c = 11111;
			a /= b;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_DivideEquals_int)
		{
			LongInt a = 2200, c = 550;
			int b = 4;
			a /= b;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_plusplus_1)
		{
			LongInt a = 99998, c = 99999;
			a++;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_plusplus_2)
		{
			LongInt a = 99998, c = 99999;
			Assert::IsFalse(a++ == c);
		}
		TEST_METHOD(Test_plusplus_Longint_1)
		{
			LongInt a = 20004, c = 20005;
			Assert::IsTrue(++a == c);
		}
		TEST_METHOD(Test_plusplus_LongInt_2)
		{
			LongInt a = 22222, c = 22223;
			++a;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_minusminus_1)
		{
			LongInt a = 99998, c = 99997;
			a--;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_minusminus_2)
		{
			LongInt a = 99999, c = 99998;
			Assert::IsFalse(a-- == c);
		}
		TEST_METHOD(Test_minusminus_Longint_1)
		{
			LongInt a = 20004, c = 20003;
			Assert::IsTrue(--a == c);
		}
		TEST_METHOD(Test_minusminus_LongInt_2)
		{
			LongInt a = 22222, c = 22221;
			--a;
			Assert::IsTrue(a == c);
		}
		TEST_METHOD(Test_LongInt_less_LongInt)
		{
			LongInt a = 110, b = 119;
			Assert::IsTrue(a < b);
		}
		TEST_METHOD(Test_LongInt_lessEquals_LongInt_1)
		{
			LongInt a = 20, b = 123124;
			Assert::IsTrue(a <= b);
		}
		TEST_METHOD(Test_LongInt_lessEquals_LongInt_2)
		{
			LongInt a = 30, b = 30;
			Assert::IsTrue(a <= b);
		}
		TEST_METHOD(Test_LongInt_less_int)
		{
			LongInt a = 110;
			int b = 120;
			Assert::IsTrue(a < b);
		}
		TEST_METHOD(Test_LongInt_lessEquals_int_1)
		{
			LongInt a = 20;
			int b = 40;
			Assert::IsTrue(a <= b);
		}
		TEST_METHOD(Test_LongInt_lessEquals_int_2)
		{
			LongInt a = 30;
			int b = 30;
			Assert::IsTrue(a <= b);
		}
		TEST_METHOD(Test_LongInt_more_LongInt)
		{
			LongInt a = 1000000, b = 99999;
			Assert::IsTrue(a > b);
		}
		TEST_METHOD(Test_LongInt_moreEquals_LongInt_1)
		{
			LongInt a = 1231240, b = 123124;
			Assert::IsTrue(a >= b);
		}
		TEST_METHOD(Test_LongInt_moreEquals_LongInt_2)
		{
			LongInt a = 30, b = 30;
			Assert::IsTrue(a >= b);
		}
		TEST_METHOD(Test_LongInt_more_int)
		{
			LongInt a = 1100;
			int b = 120;
			Assert::IsTrue(a > b);
		}
		TEST_METHOD(Test_LongInt_moreEquals_int_1)
		{
			LongInt a = 50;
			int b = 40;
			Assert::IsTrue(a >= b);
		}
		TEST_METHOD(Test_LongInt_moreEquals_int_2)
		{
			LongInt a = 30;
			int b = 30;
			Assert::IsTrue(a >= b);
		}
	};


}