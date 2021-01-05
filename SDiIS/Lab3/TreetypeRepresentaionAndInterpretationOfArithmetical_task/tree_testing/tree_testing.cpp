#include "../Project3/Expression_tree.h"
#include "../Project3/Assign_expression.h"
#include "../Project3/Math_expression.h"
#include "../Project3/Assign_expression.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testingtree
{
	TEST_CLASS(Testing_tree)
	{
	public:

		TEST_METHOD(single_positive_number_test1)
		{
			string line = "2";
			Expression_tree tree;
			tree.build_tree(line);
			int result = tree.compute_value();
			tree.delete_tree();
			Assert::AreEqual(result, 2);
		}

		TEST_METHOD(single_positive_number_test2)
		{
			string line = "100";
			Expression_tree tree;
			tree.build_tree(line);
			int result = tree.compute_value();
			tree.delete_tree();
			Assert::AreEqual(result, 100);
		}


		TEST_METHOD(single_negative_number_test1)
		{
			string line = "-2";
			Expression_tree tree;
			tree.build_tree(line);
			int result = tree.compute_value();
			tree.delete_tree();
			Assert::AreEqual(result, -2);
		}

		TEST_METHOD(single_negative_number_test2)
		{
			string line = "-100";
			Expression_tree tree;
			tree.build_tree(line);
			int result = tree.compute_value();
			tree.delete_tree();
			Assert::AreEqual(result, -100);
		}

		TEST_METHOD(operation_priority_test1)
		{
			string line = "2+2*2";
			Expression_tree tree;
			tree.build_tree(line);
			int result = tree.compute_value();
			tree.delete_tree();
			Assert::AreEqual(result, 6);
		}

		TEST_METHOD(operation_priority_test2)
		{
			string line = "3*(2+2)+1*2";
			Expression_tree tree;
			tree.build_tree(line);
			int result = tree.compute_value();
			tree.delete_tree();
			Assert::AreEqual(result, 14);
		}


		TEST_METHOD(sin_test1)
		{
			string line = "sin(0)";
			Math_expression expression;
			int result = expression.compute_value(line);
			Assert::AreEqual(result, 0);
		}

		TEST_METHOD(sin_test2)
		{
			string line = "sin(1000-500*2)";
			Math_expression expression;
			int result = expression.compute_value(line);
			Assert::AreEqual(result, 0);
		}

		TEST_METHOD(cos_test1)
		{
			string line = "cos(1)";
			Math_expression expression;
			int result = expression.compute_value(line);
			Assert::AreEqual(result, 0);
		}

		TEST_METHOD(cos_test2)
		{
			string line = "cos(1000-500*2+1)";
			Math_expression expression;
			int result = expression.compute_value(line);
			Assert::AreEqual(result, 0);
		}

		TEST_METHOD(sqrt_test1)
		{
			string line = "sqrt(4)";
			Math_expression expression;
			int result = expression.compute_value(line);
			Assert::AreEqual(result, 2);
		}

		TEST_METHOD(sqrt_test2)
		{
			string line = "sqrt(840+1)";
			Math_expression expression;
			int result = expression.compute_value(line);
			Assert::AreEqual(result, 29);
		}

		TEST_METHOD(tg_test)
		{
			string line = "tg(0)";
			Math_expression expression;
			int result = expression.compute_value(line);
			Assert::AreEqual(result, 0);
		}

		TEST_METHOD(ctg_test)
		{
			string line = "ctg(1)";
			Math_expression expression;
			int result = expression.compute_value(line);
			Assert::AreEqual(result, 0);
		}
		TEST_METHOD(log_test)
		{
			string line = "log(4)";
			Math_expression expression;
			int result = expression.compute_value(line);
			//1 becouse int values
			Assert::AreEqual(result, 1);
		}
	};

	TEST_CLASS(Testing_Assignemnt)
	{
		TEST_METHOD(assign_test_1)
		{
			Assign_expression assigment;
			string line = "a=5";
			if (assigment.is_assgignment(line))
				assigment.put_variables_into_kb(line);
			line = "a^2";
			line = assigment.assign_variables(line);
			Assert::IsTrue(line == "5^2");
		}
		TEST_METHOD(assign_test_2)
		{
			Assign_expression assigment;
			string line = "a=-5";
			if (assigment.is_assgignment(line))
				assigment.put_variables_into_kb(line);
			line = "a";
			line = assigment.assign_variables(line);
			Assert::IsTrue(line == "-5");
		}

		TEST_METHOD(assign_test_3)
		{
			Assign_expression assigment;
			string line = "a=b=5";
			if (assigment.is_assgignment(line))
				assigment.put_variables_into_kb(line);
			line = "a+b*a";
			line = assigment.assign_variables(line);
			Assert::IsTrue(line == "5+5*5");
		}

		TEST_METHOD(assign_test_4)
		{
			Assign_expression assigment;
			string line = "a=b=c=5";
			if (assigment.is_assgignment(line))
				assigment.put_variables_into_kb(line);
			line = "a+b+c";
			line = assigment.assign_variables(line);
			Assert::IsTrue(line == "5+5+5");
		}

	};


	TEST_CLASS(Testing_unary_minus)
	{
		TEST_METHOD(unary_minus_test_1)
		{
			Expression_tree tree;
			string line = "-(-(-2))";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::IsTrue(result == -2);
		}
		TEST_METHOD(unary_minus_test_2)
		{
			Expression_tree tree;
			string line = "-(-(20))";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::IsTrue(result == 20);
		}

		TEST_METHOD(unary_minus_test_3)
		{
			Expression_tree tree;
			string line = "-(-(-2-3)+(-2)-3*3)";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::IsTrue(result == 6);
		}

		TEST_METHOD(unary_minus_test_4)
		{
			Expression_tree tree;
			string line = "-(-3+3*2+3*(3-2^2))";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::IsTrue(result == 0);
		}
	};

	TEST_CLASS(Testing_math_calculations)
	{
		TEST_METHOD(division_test1)
		{
			Expression_tree tree;
			string line = "10/5";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::AreEqual(result, 2);
		}

		TEST_METHOD(division_test2)
		{
			Expression_tree tree;
			string line = "(100/2)/5/2";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::AreEqual(result, 5);
		}

		TEST_METHOD(multiplication_test1)
		{
			Expression_tree tree;
			string line = "100*12";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::AreEqual(result, 1200);
		}


		TEST_METHOD(multiplication_test2)
		{
			Expression_tree tree;
			string line = "2*3*(4*5)*2*1";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::AreEqual(result, 240);
		}


		TEST_METHOD(sum_test1)
		{
			Expression_tree tree;
			string line = "2+22";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::AreEqual(result, 24);
		}

		TEST_METHOD(sum_test2)
		{
			Expression_tree tree;
			string line = "2+3+3+22";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::AreEqual(result, 30);
		}

		TEST_METHOD(subtraction_test1)
		{
			Expression_tree tree;
			string line = "100-12";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::AreEqual(result, 88);
		}


		TEST_METHOD(subtraction_test2)
		{
			Expression_tree tree;
			string line = "120-12-(-10-3-3-1)";
			tree.build_tree(line);
			int result = tree.compute_value();
			Assert::AreEqual(result, 125);
		}

	};

}
