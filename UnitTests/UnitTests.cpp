#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <queue>
#include "Model.cpp"
#include "View.h"
#include <queue>
#include <stack>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(ModelInfixCoversion)
		{
			Model m;
			std::string input = "((11+2)*3)^2*(1+2)";
			std::queue<std::string> rpn = m.InfixToPostfix(input);
			std::string arr[] = { "11","2","+","3","*","2","^","1","2","+","*" };
			for (std::string token : arr) {
				Assert::AreEqual(rpn.front(), token);
				rpn.pop();
			}
		}
		TEST_METHOD(EvaluatePostfix)
		{
			Model m;
			std::queue<std::string> rpn;
			std::string arr[] = { "1","2","+","3","*","2","^","1","2","+","*" };
			for (std::string token : arr) {
				rpn.push(token);
			}
			double val = m.EvaluatePostfix(rpn);
			Assert::AreEqual(243.0, val);
		}
		TEST_METHOD(OrderOfOperations) 
		{
			Model m;
			queue<std::string> rpn = m.InfixToPostfix("3*10^2+(5/6+(3+2/12))");
        	double output = m.EvaluatePostfix(rpn);
			Assert::AreEqual(304.00, output);
		}
		TEST_METHOD(NegativeNumbers)
		{
			Model m;
			queue<std::string> rpn = m.InfixToPostfix("1-2+3");
			double output = m.EvaluatePostfix(rpn);
			Assert::AreEqual(2.00, output);
		}
		TEST_METHOD(RealNumbers)
		{
			Model m;
			queue<std::string> rpn = m.InfixToPostfix("3+9^(1-1.5)");
			double output = m.EvaluatePostfix(rpn);
			double val = 1.0/3 +3.0;
			Assert::AreEqual(val, output);
		}
		TEST_METHOD(BalancedBrackets)
		{
			Model m;
			queue<std::string> rpn = m.InfixToPostfix("(3+(9-10))^(2*(1-1.5))");
			double output = m.EvaluatePostfix(rpn);
			Assert::AreEqual(0.5, output);
		}
	};
}
