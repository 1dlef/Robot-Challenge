#pragma once

#include "utils.h"

class Direction {

public:
   Direction();
   Direction(eDirection);
   void RotateClockwise(size_t nStep);
   void RotateCounterClockwise(size_t nStep);

   void SetCurrectDirection(eDirection eDirection);
   const eDirection GetCurrentDirection() const;
   const std::string GetDirectionString() const;

private:
   size_t nCurrentDirection;
};