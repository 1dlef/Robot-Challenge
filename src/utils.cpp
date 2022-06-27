#include "utils.h"

bool is_number(const std::string& s)
{
   for (char const& c : s) {
      if (std::isdigit(c) == 0) return false;
   }
   return true;
}

void get_tokens(std::vector<std::string>& vTokens, std::string sString, std::string sDelim)
{
   size_t pos = 0;
   std::string sToken;

   while ((pos = sString.find(sDelim)) != std::string::npos) {
      sToken = sString.substr(0, pos);
      vTokens.push_back(sToken);
      sString.erase(0, pos + sDelim.length());
   }

   if (!sString.empty()) vTokens.push_back(sString);
}