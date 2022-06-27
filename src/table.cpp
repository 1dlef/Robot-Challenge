#include "table.h"

Table::Table(size_t _nRows, size_t _nColumns)
: nMaxRow(_nRows)
, nMaxColumn(_nColumns)
{
}

size_t Table::getRows() const
{
   return nMaxRow;
}

size_t Table::getColumns() const
{
   return nMaxColumn;
}

bool Table::isValidXPosition(size_t _nRow) const
{
   return (_nRow >= 0) && (_nRow < getRows());
}

bool Table::isValidYPosition(size_t _nCol) const
{
   return (_nCol >= 0) && (_nCol < getColumns());
}

bool Table::isValidPosition(size_t nRow, size_t nCol) const
{
   const bool bValidRow = isValidXPosition(nRow);
   const bool bValidCol = isValidYPosition(nCol);

   return (bValidRow && bValidCol);
}

bool Table::isValidPosition(tCoordinate coor) const
{
   const bool bValidRow = isValidXPosition(coor.first);
   const bool bValidCol = isValidYPosition(coor.second);

   return (bValidRow && bValidCol);
}