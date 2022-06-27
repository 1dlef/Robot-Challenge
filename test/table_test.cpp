#include "pch.h"
#include "CppUnitTest.h"
#include "robot.h"
#include "table.h"
#include "direction.h"
#include "utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tabletest
{
	TEST_CLASS(tabletest)
	{
	public:
		TEST_METHOD(Test1_Table)
		{
			Table table(MAX_ROW, MAX_COL);

			Assert::AreEqual(size_t(MAX_ROW), table.getRows());
			Assert::AreEqual(size_t(MAX_COL), table.getColumns());

			bool result = false;
			tCoordinate coor = std::make_pair(3, 4);
			Assert::AreEqual(true, table.isValidPosition(1, 4));
			Assert::AreEqual(true, table.isValidPosition(coor));

			coor = std::make_pair(9, 6);
			Assert::AreEqual(false, table.isValidPosition(1, 8));
			Assert::AreEqual(false, table.isValidPosition(coor));

			Assert::AreEqual(true, table.isValidXPosition(0));
			Assert::AreEqual(false, table.isValidXPosition(10));

			Assert::AreEqual(true, table.isValidYPosition(2));
			Assert::AreEqual(false, table.isValidYPosition(6));
		}
	};
}
