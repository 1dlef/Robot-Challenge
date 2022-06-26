#pragma once

#include "robot.h"
#include "table.h"

class Command {

public:
   virtual void execute() = 0;
};

class PlaceCmd : public Command {

public:
   PlaceCmd(Robot*, Table*);
   Robot* robot;
   Table* table;
   int iX;
   int iY;
   int iFace;

   virtual void execute() override;
};

class FaceCmd : public Command {

};

class MoveCmd : public Command {

};

class ReportCmd : public Command {

};


