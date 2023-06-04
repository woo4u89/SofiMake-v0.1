#include "loadcase.h"
#include <algorithm>
#include <cstring>
#include <string>

LoadCase LoadCase::extract(std::string& load)  
{   
   LoadCase lc;
   int _nature = static_cast<int>(load.find("*"));
   if(load.substr(0, _nature-1) == "STA")
      lc.nature = Nature::STA;
   else
      lc.nature = Nature::EKSP;    
   lc.loadNo = getLoadcaseNumber(load.substr(0, _nature)); 
   lc.factor = std::stod(load.erase(0, _nature + 1));  
   return lc;
}

int LoadCase::getLoadcaseNumber(std::string str)
{ 
   char chars[] = "STAEKSP";
   for (unsigned int i = 0; i < strlen(chars); ++i)
   {
      str.erase(std::remove(str.begin(), str.end(), chars[i]), str.end());
   }  
   return std::stoi(str);

}