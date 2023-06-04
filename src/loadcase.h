#ifndef LOADCASE_H
#define LOADCASE_H

#include <string>
// Store single load case values: SGN STA1*1.10 -> LS=LimitState::ULS, LoadCase = 1, factor = 1.1

enum class Nature
{
    STA,
    EKSP
};

class LoadCase
{   
public:    
    LoadCase extract(std::string& load);
    Nature nature; // dead_load or live_load
    int loadNo;
    double factor; //load factor
private:    
    int getLoadcaseNumber(std::string str);
}; 

#endif