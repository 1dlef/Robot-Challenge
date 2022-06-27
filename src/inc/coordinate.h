#pragma once

#include "utils.h"
#include "table.h"

class Coordinate {
public:
   explicit Coordinate(const Table& _tbl);

   size_t GetXCoordinate() const;
   size_t GetYCoordinate() const;
   void SetXCoordinate(const size_t x);
   void SetYCoordinate(const size_t y);

   void SetCoordinate(const tCoordinate& crd);
   tCoordinate& GetCoordinate();
   bool IsValidCoordinate(tCoordinate crd) const;

private:
   tCoordinate coordinate;
   const Table& tbl;
};
