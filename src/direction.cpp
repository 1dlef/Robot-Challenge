#include "direction.h"

Direction::Direction()
:nCurrentDirection(0)
{
}

void Direction::RotateClockwise(size_t nStep)
{
   for (size_t n = 1; n <= nStep; n++) {
      nCurrentDirection++;
      if (nCurrentDirection == DIRECTION_MAX) nCurrentDirection = DIRECTION_NORTH;
   }
}

void Direction::RotateCounterClockwise(size_t nStep)
{
   for (size_t n = 1; n <= nStep; n++) {
      if (nCurrentDirection == 0) nCurrentDirection = DIRECTION_WEST;
      else nCurrentDirection--;
   }
}

void Direction::SetCurrectDirection(size_t nDirection)
{
   if (nDirection < DIRECTION_MAX) nCurrentDirection = nDirection;
}

void Direction::SetCurrectDirection(std::string sDirection)
{
   for (size_t n = 0; n < DIRECTION_MAX; n++) {
      if (cDirections[n] == sDirection) nCurrentDirection = n;
   }
}

const size_t Direction::GetCurrentDirection() const
{
   return nCurrentDirection;
}

const std::string Direction::GetDirectionString() const
{
   return cDirections[nCurrentDirection];
}

bool Direction::IsValidCurrentDirection() const
{
   return ((nCurrentDirection >= 0) && (nCurrentDirection < DIRECTION_MAX));
}

bool Direction::IsValidDirectionString(std::string sDirection) const
{
   return (sDirection == "NORTH") || (sDirection == "EAST") || (sDirection == "SOUTH") || (sDirection == "WEST");
}