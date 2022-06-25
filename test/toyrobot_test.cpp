#include "pch.h"
#include "CppUnitTest.h"
#include "robot.h"
#include "table.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace toyrobottest
{
	TEST_CLASS(toyrobottest)
	{
	public:
		TEST_METHOD(Place_0_0)
		{
			Robot robot;

			robot.place(0, 0, 0, nullptr);

			Assert::AreEqual(0, robot.getXPosition());
			Assert::AreEqual(0, robot.getYPosition());
		}
	};
}
