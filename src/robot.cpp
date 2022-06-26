#include "robot.h"

using namespace std;

Robot::Robot(const Table& tbl)
:table(tbl)
{
}

void Robot::Move()
{
   const eDirection curDirection = direction.GetCurrentDirection();
   size_t xCoordinate = GetCoordinate().first;
   size_t yCoordinate = GetCoordinate().second;

   if (curDirection == DIRECTION_NORTH) SetYCoordinate(yCoordinate++);
   else if (curDirection == DIRECTION_SOUTH) SetYCoordinate(yCoordinate--);
   else if (curDirection == DIRECTION_EAST) SetXCoordinate(xCoordinate++);
   else if (curDirection == DIRECTION_WEST) SetXCoordinate(xCoordinate--);
}

void Robot::Left()
{
   direction.RotateCounterClockwise(1);
}

void Robot::Right()
{
   direction.RotateClockwise(1);
}

void Robot::Report()
{
   size_t& xCoordinate = GetCoordinate().first;
   size_t& yCoordinate = GetCoordinate().second;
   printf("Output: %zu,%zu,%s", xCoordinate, yCoordinate, direction.GetDirectionString().c_str());
}

size_t Robot::GetXCoordinate() const
{
   // Move position to table
   return coordinate.first;
}

size_t Robot::GetYCoordinate() const
{
   return coordinate.second;
}

void Robot::SetXCoordinate(const size_t x)
{
   if (!table.isValidXPosition(x)) return;

   coordinate.first = x;
}

void Robot::SetYCoordinate(const size_t y)
{
   if (!table.isValidYPosition(y)) return;
   coordinate.second = y;
}

void Robot::SetCoordinate(const tCoordinate& crd)
{
   if (!table.isValidPosition(crd)) return;

   coordinate = crd;
}

tCoordinate& Robot::GetCoordinate()
{
   return coordinate;
}

void Robot::SetDirection(const Direction& drt)
{
   direction.SetCurrectDirection(drt.GetCurrentDirection());
}

Direction& Robot::GetDirection()
{
   return direction;
}

