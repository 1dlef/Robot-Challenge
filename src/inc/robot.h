#pragma once

#include "coordinate.h"
#include "direction.h"
#include "table.h"
#include "utils.h"

class Robot: public Direction, public Coordinate {
public:
    explicit Robot(const Table& tbl);

    bool Move();
    bool Left();
    bool Right();
    bool Report();
};