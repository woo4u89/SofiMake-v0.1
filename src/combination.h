#ifndef COMBINATION_H
#define COMBINATION_H

#include <string>
#include <vector>
#include "loadcase.h"

enum class LimitState
{
    ULS = 0,
    SLS = 1
};

// store values of a single load combination as a vector of type LoadCase -> Nature, load number, factor

class Combination
{
public:
    Combination::Combination(std::string& string);
    std::vector<LoadCase> getLoadCase() const;
    LimitState getLimitState() const;

private:
    void inputLoadCaseString(std::string& string_line);
    void stringToLoadCaseVector();
    void storeLoadcase(const LoadCase& loadcase);
    void parseInput(std::string& line);

    std::vector<std::string> combinationString;
    std::vector<LoadCase> combination;
    LimitState limitstate; 

    const char plusSignDelimeter {'+'};
    const char SemicolonDelimeter {';'};
    int max_LC_dead_load{};

};

#endif