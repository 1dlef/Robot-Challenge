#include "utils.h"
#include "robot.h"
#include "table.h"
#include "command.h"
#include "cmdparser.h"

int main()
{
   Table oTable(MAX_ROW, MAX_COL);
   Robot oRobot(oTable);
   CommandParser oCmdParser;

   oCmdParser.AddCommand("PLACE", std::shared_ptr<PlaceCmd>(new PlaceCmd(oRobot)));
   oCmdParser.AddCommand("MOVE", std::shared_ptr<MoveCmd>(new MoveCmd(oRobot)));
   oCmdParser.AddCommand("LEFT", std::shared_ptr<RotateCmd>(new RotateCmd(oRobot, false)));
   oCmdParser.AddCommand("RIGHT", std::shared_ptr<RotateCmd>(new RotateCmd(oRobot, true)));
   oCmdParser.AddCommand("REPORT", std::shared_ptr<ReportCmd>(new ReportCmd(oRobot)));

   std::string sLineText;
   
   while (true) {
      std::getline(std::cin, sLineText);
      oCmdParser.ExecuteCommand(sLineText);
   }

   return 0;
}