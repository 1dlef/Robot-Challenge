#include "pch.h"
#include "CppUnitTest.h"
#include "robot.h"
#include "table.h"
#include "direction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace directiontest
{
	struct sDirExpected {
		size_t nDir;
		std::string sDir;
	};

	static const sDirExpected test1_expected[] = {
		{DIRECTION_NORTH,  cDirections[DIRECTION_NORTH]},
		{DIRECTION_EAST,   cDirections[DIRECTION_EAST]},
		{DIRECTION_SOUTH,  cDirections[DIRECTION_SOUTH]},
		{DIRECTION_WEST,   cDirections[DIRECTION_WEST]},
		{DIRECTION_NORTH,  cDirections[DIRECTION_NORTH]},
		{DIRECTION_EAST,   cDirections[DIRECTION_EAST]},
		{DIRECTION_SOUTH,  cDirections[DIRECTION_SOUTH]},
		{DIRECTION_WEST,   cDirections[DIRECTION_WEST]},
	};

	static const sDirExpected test2_expected[] = {
		{DIRECTION_NORTH,  cDirections[DIRECTION_NORTH]},
		{DIRECTION_WEST,   cDirections[DIRECTION_WEST]},
		{DIRECTION_SOUTH,  cDirections[DIRECTION_SOUTH]},
		{DIRECTION_EAST,   cDirections[DIRECTION_EAST]},
		{DIRECTION_NORTH,  cDirections[DIRECTION_NORTH]},
		{DIRECTION_WEST,   cDirections[DIRECTION_WEST]},
		{DIRECTION_SOUTH,  cDirections[DIRECTION_SOUTH]},
		{DIRECTION_EAST,   cDirections[DIRECTION_EAST]},
	};

	TEST_CLASS(direction_test)
	{
	public:
		TEST_METHOD(Test1_Rotate_Clockwise)
		{
			Direction oDirection;
			oDirection.SetCurrectDirection(DIRECTION_WEST);

			for (size_t n = 0; n < 8; n++) {
				oDirection.RotateClockwise(1);
				Assert::AreEqual(test1_expected[n].nDir, oDirection.GetCurrentDirection());
				Assert::AreEqual(test1_expected[n].sDir.c_str(), oDirection.GetDirectionString().c_str());
			}
		}
		TEST_METHOD(Test2_Rotate_CounterClockwise)
		{
			Direction oDirection;
			oDirection.SetCurrectDirection(DIRECTION_EAST);

			for (size_t n = 0; n < 8; n++) {
				oDirection.RotateCounterClockwise(1);
				Assert::AreEqual(test2_expected[n].nDir, oDirection.GetCurrentDirection());
				Assert::AreEqual(test2_expected[n].sDir.c_str(), oDirection.GetDirectionString().c_str());
			}
		}
	};
}
