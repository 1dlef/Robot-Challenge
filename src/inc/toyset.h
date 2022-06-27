#pragma once

#include "robot.h"
#include "table.h"
#include "utils.h"

class ToySet {
public:
   void AddRobotInTable(Robot* robot, Table* table);
private:

   void CheckCoordinatesInTable(tCoordinate coor, const Table& table);
   std::vector<Robot> vRobots;
   std::vector<Table> vTable;
   std::map<Robot, Table> mRobotLocator;
};