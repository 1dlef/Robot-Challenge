#pragma once

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

enum {
   MAX_ROW = 5,
   MAX_COL = 5
};

typedef enum {
   DIRECTION_NORTH,
   DIRECTION_EAST,
   DIRECTION_SOUTH,
   DIRECTION_WEST,
   DIRECTION_INVALID
} eDirection;

typedef std::pair<size_t, size_t> tCoordinate;
