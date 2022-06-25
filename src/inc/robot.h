#pragma once

#include <iostream>
#include <map>
#include <string>
#include "table.h"

typedef enum {
   NORTH = 0,
   EAST,
   SOUTH,
   WEST,
   DIRECTION_MAX
} tDirection;

class Robot {
public:
    Robot();
    bool place(int x, int y, int direction, Table* pTable);
    bool move();
    void left();
    void right();
    void report();

    bool isInsideTable() const;

    int getXPosition() const;
    int getYPosition() const;

private:

   bool moveNorth();
   bool moveSouth();
   bool moveEast();
   bool moveWest();

   int iXPosition;
   int iYPosition;
   int iDirection;

   bool bInsideTable;

   std::map<const int, std::string> mDirection;
   Table* pTable;
};