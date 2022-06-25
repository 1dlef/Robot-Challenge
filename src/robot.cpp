#include "robot.h"

using namespace std;

Robot::Robot()
: iXPosition(-1)
, iYPosition(-1)
, iDirection(DIRECTION_MAX)
, pTable(nullptr)
, bInsideTable(false)
{
   mDirection.insert(make_pair(NORTH, "NORTH"));
   mDirection.insert(make_pair(EAST, "EAST"));
   mDirection.insert(make_pair(SOUTH, "SOUTH"));
   mDirection.insert(make_pair(WEST, "WEST"));
}

bool Robot::place(int x, int y, int direction, Table* _pTable)
{
   if (!_pTable->isValidPosition(x, y)) return false;

   iXPosition = x;
   iYPosition = y;
   iDirection = direction;
   bInsideTable = true;
   pTable = _pTable;

   return true;
}

bool Robot::move()
{
   if (!isInsideTable()) return false;

   bool result = false;

   if (iDirection == NORTH) result = moveNorth();
   else if (iDirection == SOUTH) result= moveSouth();
   else if (iDirection == EAST) result = moveEast();
   else if (iDirection = WEST) result= moveWest();

   return result;
}

void Robot::left()
{
   if (!isInsideTable()) return;

   iDirection = (iDirection - 1) ;
   if (iDirection < 0) iDirection = WEST;
}

void Robot::right()
{
   if (!isInsideTable()) return;

   iDirection = (iDirection + 1) % DIRECTION_MAX;
}

void Robot::report()
{
   if (!isInsideTable()) return;

   auto result =  mDirection.find(iDirection);

   if (result == mDirection.end()) return; // Not found

   printf("Output: %d,%d,%s", iXPosition, iYPosition, mDirection[iDirection].c_str());
}

bool Robot::isInsideTable() const
{
   return bInsideTable && (pTable != nullptr);
}

int Robot::getXPosition() const
{
   // Move position to table
   return iXPosition;
}

int Robot::getYPosition() const
{
   return iYPosition;
}

bool Robot::moveNorth()
{
   if (!isInsideTable()) return false;
   if (!pTable->isValidXPosition(iXPosition + 1)) return false;

   iXPosition++;
   return true;
}

bool Robot::moveSouth()
{
   if (!isInsideTable()) return false;
   if (!pTable->isValidXPosition(iXPosition - 1)) return false;

   iXPosition--;
   return true;
}

bool Robot::moveEast()
{
   if (!isInsideTable()) return false;
   if (!pTable->isValidYPosition(iYPosition + 1)) return false;

   iYPosition++;
   return true;
}

bool Robot::moveWest()
{
   if (!isInsideTable()) return false;
   if (!pTable->isValidYPosition(iYPosition - 1)) return false;

   iYPosition--;
   return true;
}





