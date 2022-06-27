#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <utility>
#include <vector>

#define MAX_COMMAND_LEN 17

enum {
   MAX_ROW = 5,
   MAX_COL = 5
};

typedef std::pair<size_t, size_t> tCoordinate;

bool is_number(const std::string& s);
void get_tokens(std::vector<std::string>& vTokens, std::string sString, std::string sDelim);
