// Keeps track of the robot
#include "table.h"

Table::Table(int _iRows, int _iColumns)
: iMaxRow(_iRows)
, iMaxColumn(_iColumns)
, bRobotPresent(false)
{
}

int Table::getRows() const
{
   return iMaxRow;
}

int Table::getColumns() const
{
   return iMaxColumn;
}

bool Table::isValidXPosition(int _iRow) const
{
   return (_iRow > 0) && (_iRow < getRows());
}

bool Table::isValidYPosition(int _iCol) const
{
   return (_iCol > 0) && (_iCol < getColumns());
}

bool Table::isValidPosition(int iRow, int iCol) const
{
   const bool bValidRow = isValidXPosition(iRow);
   const bool bValidCol = isValidYPosition(iCol);

   return (bValidRow && bValidCol);
}

bool Table::isRobotPresent() const
{
   return bRobotPresent;
}
