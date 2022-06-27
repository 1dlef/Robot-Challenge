#include "pch.h"
#include "CppUnitTest.h"
#include "robot.h"
#include "table.h"
#include "direction.h"
#include "utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace robottest
{
	TEST_CLASS(robottest)
	{
	public:
		TEST_METHOD(Test1_Move)
		{
			Table table(MAX_ROW, MAX_COL);
			Robot robot(table);
			tCoordinate coor = std::make_pair(0, 0);
			robot.SetCoordinate(coor);
			robot.SetCurrectDirection(DIRECTION_EAST);

			// Move to max row
			for (size_t n = 0; n < MAX_ROW - 1; n++) {
				robot.Move();
				Assert::AreEqual(size_t(n+1), robot.GetXCoordinate());
				Assert::AreEqual(size_t(0), robot.GetYCoordinate());
			}

			// Move to max col
			robot.SetCoordinate(coor);
			robot.SetCurrectDirection(DIRECTION_NORTH);
			for (size_t n = 0; n < MAX_ROW - 1; n++) {
				robot.Move();
				Assert::AreEqual(size_t(0), robot.GetXCoordinate());
				Assert::AreEqual(size_t(n+1), robot.GetYCoordinate());
			}

			// Place robot in top corner, robot should not move beyond row
			coor = std::make_pair(4, 4);
			robot.SetCoordinate(coor);
			robot.SetCurrectDirection(DIRECTION_EAST);
			robot.Move();
			Assert::AreEqual(size_t(4), robot.GetXCoordinate());
			Assert::AreEqual(size_t(4), robot.GetYCoordinate());
			
			// Place robot in top corner, robot should not move beyond column
			robot.SetCurrectDirection(DIRECTION_NORTH);
			robot.Move();
			Assert::AreEqual(size_t(4), robot.GetXCoordinate());
			Assert::AreEqual(size_t(4), robot.GetYCoordinate());
		}

		TEST_METHOD(Test2_Left)
		{
			Table table(MAX_ROW, MAX_COL);
			Robot robot(table);
			tCoordinate coor = std::make_pair(0, 0);
			robot.SetCoordinate(coor);
			robot.SetCurrectDirection(DIRECTION_EAST);

			robot.Left();
			Assert::AreEqual("NORTH", robot.GetDirectionString().c_str());
			robot.Left();
			Assert::AreEqual("WEST", robot.GetDirectionString().c_str());
			robot.Left();
			Assert::AreEqual("SOUTH", robot.GetDirectionString().c_str());
			robot.Left();
			Assert::AreEqual("EAST", robot.GetDirectionString().c_str());
		}

		TEST_METHOD(Test3_Right)
		{
			Table table(MAX_ROW, MAX_COL);
			Robot robot(table);
			tCoordinate coor = std::make_pair(0, 0);
			robot.SetCoordinate(coor);
			robot.SetCurrectDirection(DIRECTION_WEST);

			robot.Right();
			Assert::AreEqual("NORTH", robot.GetDirectionString().c_str());
			robot.Right();
			Assert::AreEqual("EAST", robot.GetDirectionString().c_str());
			robot.Right();
			Assert::AreEqual("SOUTH", robot.GetDirectionString().c_str());
			robot.Right();
			Assert::AreEqual("WEST", robot.GetDirectionString().c_str());
		}

		TEST_METHOD(Test4_Report)
		{
		}
	};
}
