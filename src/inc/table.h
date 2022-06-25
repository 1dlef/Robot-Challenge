#pragma once

class Table {
public:
   Table(int iRow, int iColumn);

   int getRows() const;
   int getColumns() const;

   bool isValidXPosition(int iRow) const;
   bool isValidYPosition(int iCol) const;
   bool isValidPosition(int iRow, int iCol) const;

   bool isRobotPresent() const;

private:
   int iMaxRow;
   int iMaxColumn;
   bool bRobotPresent;

   //std::vector<Robot> vRobot;
};