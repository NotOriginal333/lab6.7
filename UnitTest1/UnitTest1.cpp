#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.7/Array.h"
#include "../lab6.7/Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestReplace)
		{
			Array arr(5);
			arr[0] = -16;
			arr[1] = 2;
			arr[2] = -35;
			arr[3] = 43;
			arr[4] = -47;

			arr.replace();

			Assert::AreEqual(45.0, arr[0]);
			Assert::AreEqual(45.0, arr[1]);
			Assert::AreEqual(-35.0, arr[2]);
			Assert::AreEqual(43.0, arr[3]);
			Assert::AreEqual(-47.0, arr[4]);
		}

		TEST_METHOD(TestSumAverage)
		{
			Array arr(5);
			arr[0] = -16;
			arr[1] = 2;
			arr[2] = -35;
			arr[3] = 43;
			arr[4] = -47;

			arr.sumAverage();

			Assert::AreEqual(143.0, arr[5]);
			Assert::AreEqual(28.6, arr[6]);
		}
	};
}
