#include "pch.h"
#include "CppUnitTest.h"
#include "robot.h"
#include "table.h"
#include "direction.h"
#include "command.h"
#include "utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace commandtest
{
	TEST_CLASS(commandtest)
	{
	public:
		TEST_METHOD(Test1_PlaceCmd)
		{
			Table oTable(MAX_ROW, MAX_COL);
			Robot oRobot(oTable);
			PlaceCmd oPlaceCmd(oRobot);

			Assert::AreEqual(true, oPlaceCmd.execute("1,2,NORTH"));
			Assert::AreEqual(false, oPlaceCmd.execute("6,6,NORTH"));
			Assert::AreEqual(false, oPlaceCmd.execute("1,2,NrTH"));
			Assert::AreEqual(false, oPlaceCmd.execute("a,2,NrTH"));
			Assert::AreEqual(false, oPlaceCmd.execute(""));

			Command::bInit = false; // Just to reset
		}

		TEST_METHOD(Test2_MoveCmd)
		{
			Table oTable(MAX_ROW, MAX_COL);
			Robot oRobot(oTable);
			MoveCmd oMoveCmd(oRobot);
			PlaceCmd oPlaceCmd(oRobot);

			// Should not accept since "PLACE" command is not yet executed
			Assert::AreEqual(false, oMoveCmd.execute(""));
			Assert::AreEqual(true, oPlaceCmd.execute("1,2,NORTH"));

			Assert::AreEqual(true, oMoveCmd.execute(""));
			Assert::AreEqual(false, oMoveCmd.execute("1,2,NORTH"));

			Command::bInit = false; // Just to reset

		}
		TEST_METHOD(Test4_RotateCmd_Left)
		{
			Table oTable(MAX_ROW, MAX_COL);
			Robot oRobot(oTable);
			RotateCmd oRotateCmd(oRobot, false);
			PlaceCmd oPlaceCmd(oRobot);

			// Should not accept since "PLACE" command is not yet executed
			Assert::AreEqual(false, oRotateCmd.execute(""));
			Assert::AreEqual(true, oPlaceCmd.execute("1,2,NORTH"));

			Assert::AreEqual(true, oRotateCmd.execute(""));
			Assert::AreEqual(false, oRotateCmd.execute("1,2,NORTH"));

			Command::bInit = false; // Just to reset
		}
		TEST_METHOD(Test4_RotateCmd_Right)
		{
			Table oTable(MAX_ROW, MAX_COL);
			Robot oRobot(oTable);
			RotateCmd oRotateCmd(oRobot, true);
			PlaceCmd oPlaceCmd(oRobot);

			// Should not accept since "PLACE" command is not yet executed
			Assert::AreEqual(false, oRotateCmd.execute(""));
			Assert::AreEqual(true, oPlaceCmd.execute("1,2,NORTH"));

			Assert::AreEqual(true, oRotateCmd.execute(""));
			Assert::AreEqual(false, oRotateCmd.execute("1,2,NORTH"));

			Command::bInit = false; // Just to reset
		}

		TEST_METHOD(Test4_ReportCmd)
		{
			Table oTable(MAX_ROW, MAX_COL);
			Robot oRobot(oTable);
			ReportCmd oReportCmd(oRobot);
			PlaceCmd oPlaceCmd(oRobot);

			// Should not accept since "PLACE" command is not yet executed
			Assert::AreEqual(false, oReportCmd.execute(""));
			Assert::AreEqual(true, oPlaceCmd.execute("1,2,NORTH"));

			Assert::AreEqual(true, oReportCmd.execute(""));
			Assert::AreEqual(false, oReportCmd.execute("1,2,NORTH"));

			Command::bInit = false; // Just to reset
		}
	};
}
