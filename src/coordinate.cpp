#include "coordinate.h"

Coordinate::Coordinate(const Table& _tbl)
:tbl(_tbl)
{
}

size_t Coordinate::GetXCoordinate() const
{
   return coordinate.first;
}

size_t Coordinate::GetYCoordinate() const
{
   return coordinate.second;
}

void Coordinate::SetXCoordinate(const size_t x)
{
   if (!tbl.isValidXPosition(x)) return;
   coordinate.first = x;
}

void Coordinate::SetYCoordinate(const size_t y)
{
   if (!tbl.isValidYPosition(y)) return;
   coordinate.second = y;
}

void Coordinate::SetCoordinate(const tCoordinate& crd)
{
   if (!tbl.isValidPosition(crd)) return;
   coordinate = crd;
}

tCoordinate& Coordinate::GetCoordinate()
{
   return coordinate;
}

bool Coordinate::IsValidCoordinate(tCoordinate crd) const
{
   return tbl.isValidPosition(crd);
}