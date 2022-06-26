#include "pch.h"
#include "CppUnitTest.h"
#include "robot.h"
#include "table.h"
#include "direction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace toyrobottest
{
	TEST_CLASS(toyrobottest)
	{
	public:
		TEST_METHOD(Place_0_0)
		{
			//Robot robot;

			//robot.place(0, 0, 0, nullptr);

			//Assert::AreEqual(0, robot.getXPosition());
			//Assert::AreEqual(0, robot.getYPosition());
		}
	};

	TEST_CLASS(direction_test)
	{
	public:
		TEST_METHOD(Rotate_Clockwise)
		{
			Direction oDirection(DIRECTION_NORTH);

			oDirection.RotateClockwise(1);
			Assert::AreEqual(int(DIRECTION_EAST), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("EAST", oDirection.GetDirectionString().c_str());

			oDirection.RotateClockwise(1);
			Assert::AreEqual(int(DIRECTION_SOUTH), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("SOUTH", oDirection.GetDirectionString().c_str());

			oDirection.RotateClockwise(1);
			Assert::AreEqual(int(DIRECTION_WEST), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("WEST", oDirection.GetDirectionString().c_str());

			oDirection.RotateClockwise(1);
			Assert::AreEqual(int(DIRECTION_NORTH), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("NORTH", oDirection.GetDirectionString().c_str());

			oDirection.RotateClockwise(2);
			Assert::AreEqual(int(DIRECTION_SOUTH), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("SOUTH", oDirection.GetDirectionString().c_str());

			oDirection.RotateClockwise(3);
			Assert::AreEqual(int(DIRECTION_EAST), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("EAST", oDirection.GetDirectionString().c_str());
		}

		TEST_METHOD(Rotate_CounterClockwise)
		{
			Direction oDirection(DIRECTION_NORTH);

			oDirection.RotateCounterClockwise(1);
			Assert::AreEqual(int(DIRECTION_WEST), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("WEST", oDirection.GetDirectionString().c_str());

			oDirection.RotateCounterClockwise(1);
			Assert::AreEqual(int(DIRECTION_SOUTH), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("SOUTH", oDirection.GetDirectionString().c_str());

			oDirection.RotateCounterClockwise(1);
			Assert::AreEqual(int(DIRECTION_EAST), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("EAST", oDirection.GetDirectionString().c_str());

			oDirection.RotateCounterClockwise(1);
			Assert::AreEqual(int(DIRECTION_NORTH), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("NORTH", oDirection.GetDirectionString().c_str());

			oDirection.RotateCounterClockwise(2);
			Assert::AreEqual(int(DIRECTION_SOUTH), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("SOUTH", oDirection.GetDirectionString().c_str());

			oDirection.RotateCounterClockwise(3);
			Assert::AreEqual(int(DIRECTION_WEST), int(oDirection.GetCurrentDirection()));
			Assert::AreEqual("WEST", oDirection.GetDirectionString().c_str());
		}
	};
}
