#pragma once

#include "utils.h"

typedef enum {
   DIRECTION_NORTH = 0,
   DIRECTION_EAST,
   DIRECTION_SOUTH,
   DIRECTION_WEST,
   DIRECTION_MAX
} eDirection;

static const char* cDirections[] = {
   "NORTH",
   "EAST",
   "SOUTH",
   "WEST"
};

class Direction {
public:
   Direction();
   void RotateClockwise(size_t nStep);
   void RotateCounterClockwise(size_t nStep);

   void SetCurrectDirection(size_t nDirection);
   void SetCurrectDirection(std::string sDirection);
   const size_t GetCurrentDirection() const;
   const std::string GetDirectionString() const;

   bool IsValidCurrentDirection() const;
   bool IsValidDirectionString(std::string str) const;

private:
   size_t nCurrentDirection;
};