#include "combination.h"
#include <sstream>
#include <algorithm>


Combination::Combination(std::string& string)
{
    inputLoadCaseString(string);
    stringToLoadCaseVector();
}

void Combination::storeLoadcase(const LoadCase& loadcase)
{
combination.push_back(loadcase);
}

std::vector<LoadCase> Combination::getLoadCase() const 
{
return combination;
}

LimitState Combination::getLimitState() const
{
return limitstate; 
}

void Combination::inputLoadCaseString(std::string& string_line)
{
    parseInput(string_line); 
    std::string singleLoad; 

    string_line.erase(remove(string_line.begin(), string_line.end(), '+'),string_line.end());
    std::stringstream ss {string_line};
    while(ss >> singleLoad)
    {
        combinationString.push_back(singleLoad);    
    }  
}


void Combination::stringToLoadCaseVector()
{
    LoadCase load;
    for(std::string singleLoad : combinationString)
    {
    LoadCase LC = load.extract(singleLoad);
    if (LC.nature == Nature::STA)
        ++max_LC_dead_load;
    else
        LC.loadNo +=max_LC_dead_load;    
    storeLoadcase(LC);
    }
}

void Combination::parseInput(std::string& line)
{
    limitstate = (line.substr(0,3) == "SGN") ? LimitState::ULS : LimitState::SLS;  

    int cut = static_cast<int>(line.find(SemicolonDelimeter)) + 1;
    line.erase(0, cut); 
}
