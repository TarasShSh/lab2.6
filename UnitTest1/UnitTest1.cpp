#include "pch.h"
#include "CppUnitTest.h"

#include "../lab2.6/lab2.6.cpp"
#include "../lab2.6/SolutionC.h"
#include "../lab2.6/SolutionC.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

			SolutionC b;
			b.setAmount(1500);
			Assert::AreEqual(1500, b.getAmount());

			SolutionC z1();
			SolutionC::Liquid z2();
			int za = SolutionC::getCounter();
			int zb = SolutionC::Liquid::getCounter();
			Assert::AreEqual(za, 1);
			SolutionC s("Сольовий");
			SolutionC::Liquid l("Дивний", 99);
			int sa = SolutionC::getCounter();
			int sb = SolutionC::Liquid::getCounter();
			Assert::AreEqual(sa, 2);
		}
	};
}
