#pragma once

#include "utils.h"
#include "command.h"

class CommandParser {
public:
   CommandParser();

   bool AddCommand(std::string str, std::shared_ptr<Command> cmd);
   bool ExecuteCommand(std::string sCmd);

private:
      CommandParser(CommandParser const& copy);            // Not Implemented
      CommandParser& operator=(CommandParser const& copy); // Not Implemented
      std::map<std::string, std::shared_ptr<Command>> cmd;
};