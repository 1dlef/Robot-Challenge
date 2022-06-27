#include "robot.h"

Robot::Robot(const Table& _tbl)
 :Coordinate(_tbl)
{
}

bool Robot::Move()
{
   const size_t curDirection = GetCurrentDirection();
   size_t xCoordinate = GetCoordinate().first;
   size_t yCoordinate = GetCoordinate().second;

   if (curDirection == DIRECTION_NORTH) SetYCoordinate(yCoordinate + 1);
   else if (curDirection == DIRECTION_SOUTH) SetYCoordinate(yCoordinate - 1);
   else if (curDirection == DIRECTION_EAST) SetXCoordinate(xCoordinate + 1);
   else if (curDirection == DIRECTION_WEST) SetXCoordinate(xCoordinate - 1);

   return IsValidCurrentDirection();
}

bool Robot::Left()
{
   RotateCounterClockwise(1);
   return IsValidCurrentDirection();
}

bool Robot::Right()
{
   RotateClockwise(1);
   return IsValidCurrentDirection();
}

bool Robot::Report()
{
   printf("Output: %zu,%zu,%s\n", GetCoordinate().first, GetCoordinate().second, GetDirectionString().c_str());
   return true;
}

