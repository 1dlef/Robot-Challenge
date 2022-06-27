#include "command.h"

bool Command::bInit = false;

PlaceCmd::PlaceCmd(Robot& rbt)
:robot(rbt)
{
}

bool PlaceCmd::execute(std::string params)
{
   tCoordinate crd;
   std::string delimiter = ",";
   std::vector<std::string> vTokens;

   get_tokens(vTokens, params, delimiter);

   if (vTokens.size() == 0 || vTokens.size() > 3) return false; // Only accept 3 for now

   if (is_number(vTokens[0])) sscanf_s(vTokens[0].c_str(), "%zu", &crd.first);
   if (is_number(vTokens[1])) sscanf_s(vTokens[1].c_str(), "%zu", &crd.second);

   if (robot.IsValidCoordinate(crd) && robot.IsValidDirectionString(vTokens[2])) {
      robot.SetCoordinate(crd);
      robot.SetCurrectDirection(vTokens[2]);
      bInit = true;

      return true;
   }

   return false;
}

RotateCmd::RotateCmd(Robot& rbt, bool bCw)
: robot(rbt)
, bClockWise(bCw)
{
}

bool RotateCmd::execute(std::string params)
{
   if (!bInit) return false;
   if (!params.empty()) return false; // For now, don't accept params. This can be number of rotation steps 
   bool result;

   if (bClockWise) result = robot.Right();
   else result = robot.Left();

   return result;

}

MoveCmd::MoveCmd(Robot& rbt)
: robot(rbt)
{
}

bool MoveCmd::execute(std::string params)
{
   if (!bInit) return false;
   if (!params.empty()) return false; // For now, don't accept params. This can be number of moves

   return robot.Move();
}

ReportCmd::ReportCmd(Robot& rbt)
:robot(rbt)
{
}

bool ReportCmd::execute(std::string params)
{
   if (!bInit) return false;
   if (!params.empty()) return false;

   return robot.Report();
}