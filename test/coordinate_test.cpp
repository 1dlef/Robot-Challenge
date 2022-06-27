#include "pch.h"
#include "CppUnitTest.h"
#include "robot.h"
#include "table.h"
#include "direction.h"
#include "utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace coordinatetest
{
	TEST_CLASS(coordinatetest)
	{
	public:
		TEST_METHOD(Test1_Coordinate)
		{
			Table oTable(MAX_ROW, MAX_COL);
			Coordinate oCoor(oTable);

			tCoordinate coor = std::make_pair(3, 4);

			oCoor.SetCoordinate(coor);
			Assert::AreEqual(size_t(3), oCoor.GetXCoordinate());
			Assert::AreEqual(size_t(4), oCoor.GetYCoordinate());
			Assert::AreEqual(true, oCoor.IsValidCoordinate(coor));

			coor = std::make_pair(9, 6);
			Assert::AreEqual(false, oCoor.IsValidCoordinate(coor));
		}
	};
}
