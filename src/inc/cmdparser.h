#pragma once

#include "utils.h"
#include "command.h"

// TODO: this can be improved to decouple the parsing logic
class CommandParser {
public:
   CommandParser();

   bool AddCommand(std::string str, std::shared_ptr<Command> cmd);
   bool ExecuteCommand(std::string sCmdParam); // Accepts string as <command> <param>

private:
      CommandParser(CommandParser const& copy);            // Not Implemented
      CommandParser& operator=(CommandParser const& copy); // Not Implemented
      std::map<std::string, std::shared_ptr<Command>> cmd;
};