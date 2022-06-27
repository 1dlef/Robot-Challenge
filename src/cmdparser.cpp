#include "cmdparser.h"

CommandParser::CommandParser()
{
}

bool CommandParser::AddCommand(std::string str, std::shared_ptr<Command> pcmd)
{
   if (cmd.find(str) != cmd.end()) return false; // Not yet added

   cmd.insert(make_pair(str, pcmd));

   return true;
}

bool CommandParser::ExecuteCommand(std::string sCmd)
{
   if (sCmd.empty()) return false;

   std::string delimiter_space = " ";

   size_t pos = 0;
   bool result = false;

   std::vector<std::string> vString;
   get_tokens(vString, sCmd, delimiter_space);

   if (cmd.find(vString[0]) == cmd.end()) return false;                          // Command is not found
   if (vString.size() == 1) result = cmd[vString[0]].get()->execute("");         // Command with no params
   if (vString.size() == 2) result = cmd[vString[0]].get()->execute(vString[1]); // Command with param

   return result;
}