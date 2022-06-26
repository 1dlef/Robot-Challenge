#include "utils.h"
#include "robot.h"
#include "table.h"
#include "command.h"

int main()
{
   Table oTable(MAX_ROW, MAX_COL);
   Robot oRobot(oTable);
   std::string text;

   while (true) {
      std::cin >> text;

      if(strcmp(text.c_str(), "x") == 0) break;
   }

   return 0;
}