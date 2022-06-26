#pragma once
#include "utils.h"
#include "direction.h"
#include "table.h"

class Robot {
public:
    explicit Robot(const Table& tbl);

    void Move();
    void Left();
    void Right();
    void Report();

    size_t GetXCoordinate() const;
    size_t GetYCoordinate() const;
    void SetXCoordinate(const size_t x);
    void SetYCoordinate(const size_t y);

    void SetCoordinate(const tCoordinate& crd );
    tCoordinate& GetCoordinate();

    void SetDirection(const Direction& drt);
    Direction& GetDirection();

private:
   tCoordinate coordinate;
   Direction direction;

   const Table& table;
};