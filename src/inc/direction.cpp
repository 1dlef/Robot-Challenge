#include "direction.h"

Direction::Direction()
:nCurrentDirection(DIRECTION_INVALID)
{
}

Direction::Direction(eDirection _eDirection)
:nCurrentDirection(_eDirection)
{
}

void Direction::RotateClockwise(size_t nStep)
{
   for (size_t n = 1; n <= nStep; n++) {
      nCurrentDirection++;
      if (nCurrentDirection == DIRECTION_INVALID) nCurrentDirection = DIRECTION_NORTH;
   }
}

void Direction::RotateCounterClockwise(size_t nStep)
{
   for (size_t n = 1; n <= nStep; n++) {
      if (nCurrentDirection == 0) nCurrentDirection = DIRECTION_WEST;
      else nCurrentDirection--;
   }
}

void Direction::SetCurrectDirection(eDirection eDirection)
{
   nCurrentDirection = eDirection;
}

const eDirection Direction::GetCurrentDirection() const
{
   if (nCurrentDirection == 0) return DIRECTION_NORTH;
   else if (nCurrentDirection == 1) return DIRECTION_EAST;
   else if (nCurrentDirection == 2) return DIRECTION_SOUTH;
   else if (nCurrentDirection == 3) return DIRECTION_WEST;
   else return DIRECTION_INVALID;
}

const std::string Direction::GetDirectionString() const
{
   if (nCurrentDirection == 0) return "NORTH";
   else if (nCurrentDirection == 1) return "EAST";
   else if (nCurrentDirection == 2) return "SOUTH";
   else if (nCurrentDirection == 3) return "WEST";
   else return "INVALID";
}