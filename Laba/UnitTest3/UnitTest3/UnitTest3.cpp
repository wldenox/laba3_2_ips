#include "pch.h"
#include "CppUnitTest.h"
#include "laba3_2\laba3_2\laba3_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(calculate_Tests)
	{
	public:

		TEST_METHOD(calculate_Tests_1)
		{

			double a = 5.0, b = 60.0, h = 3.0;
			int n = 6;
			double excepted = 177.211;
			double actual = solve(a, n); 

	
			Assert::AreEqual(excepted, actual, 0.01);

		}

		TEST_METHOD(calculate_Tests_2)
		{

			double a = 6.0, b = 10.0, h = 5.0;
			int n = 3;
			double expected = 58.6;
			double actual = solve(a, n); 

			Assert::AreEqual(expected , actual, 0.01);

		

		}
		TEST_METHOD(calculate_Tests_3)
		{

			double a = 2.0, b = 5.0, h = 3.0;
			int n = 6;
			double excepted = 177.211;
			double actual = solve(a, n);


			Assert::AreEqual(excepted, actual, 0.01);

		}
	};
	TEST_CLASS(checkValidParams_Tests) {
	public:

	TEST_METHOD(checkValidParams_get2_) {
		double a = 2.0, b = 3.0, h = 3.0;
		int n = 4;
		try {
			CheckValidParams(a,b,h,n);
			Assert::IsTrue(true);
		}
		catch (...) {
			Assert::Fail();
		}
	}
	TEST_METHOD(checkValidParams_get10_exceptionNotThrown) {
		double a = 4.0, b = 2.0, h = 3.0;
		int n = 1;
		try {
			CheckValidParams(a, b, h, n);
			Assert::Fail();
		}
		catch (...) {
			Assert::IsTrue(true);
		}
	}












	};

}
