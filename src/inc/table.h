#pragma once
#include "utils.h"

class Table {
public:
   explicit Table(size_t nRow, size_t nColumn);

   size_t getRows() const;
   size_t getColumns() const;

   bool isValidXPosition(size_t nRow) const;
   bool isValidYPosition(size_t nCol) const;
   bool isValidPosition(size_t nRow, size_t nCol) const;
   bool isValidPosition(tCoordinate coor) const;

private:
   size_t nMaxRow;
   size_t nMaxColumn;
};
