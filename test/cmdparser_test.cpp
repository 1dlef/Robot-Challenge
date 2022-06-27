#include "pch.h"
#include "CppUnitTest.h"
#include "robot.h"
#include "table.h"
#include "direction.h"
#include "utils.h"
#include "cmdparser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace cmdparsertest
{
	TEST_CLASS(cmdparsertest)
	{
	public:
		TEST_METHOD(Test1_CmdParser)
		{
			bool bResult;
			Table oTable(MAX_ROW, MAX_COL);
			Robot oRobot(oTable);
			CommandParser oCmdParser;

			bResult = oCmdParser.AddCommand("PLACE", std::shared_ptr<PlaceCmd>(new PlaceCmd(oRobot)));
			Assert::AreEqual(true, bResult);
			bResult = oCmdParser.AddCommand("MOVE", std::shared_ptr<MoveCmd>(new MoveCmd(oRobot)));
			Assert::AreEqual(true, bResult);

			// Already exist
			bResult = oCmdParser.AddCommand("PLACE", std::shared_ptr<RotateCmd>(new RotateCmd(oRobot, false)));
			Assert::AreEqual(false, bResult);

			bResult = oCmdParser.ExecuteCommand("PLACE 1,2,NORTH");
			Assert::AreEqual(true, bResult);

			// Command not supported
			bResult = oCmdParser.ExecuteCommand("LEFT");
			Assert::AreEqual(false, bResult);
		}
	};
}
