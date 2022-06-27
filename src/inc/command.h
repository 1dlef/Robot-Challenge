#pragma once

#include "robot.h"
#include "table.h"

class Command {
public:
   virtual bool execute(std::string params) = 0;
   static bool bInit;
};

class PlaceCmd:public Command {
public:
   PlaceCmd(Robot&);
   Robot& robot;

   virtual bool execute(std::string params) override;
};

class RotateCmd : public Command {
public:
   RotateCmd(Robot&, bool bClockWise);
   Robot& robot;

   virtual bool execute(std::string params) override;

private:
   bool bClockWise;
};

class MoveCmd : public Command {
public:
   MoveCmd(Robot&);
   Robot& robot;

   virtual bool execute(std::string params) override;
};

class ReportCmd : public Command {
public:
   ReportCmd(Robot&);
   Robot& robot;

   virtual bool execute(std::string params) override;
};


