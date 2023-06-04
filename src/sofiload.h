#ifndef SOFILOAD_H
#define SOFILOAD_H

#include "combination.h"
#include "loadcase.h"
#include <fstream>
#include <string>
#include <memory>

const int ULS_LC_START = 1001;
const int SLS_LC_START = 1301;

class Sofiload 
{
public:
    Sofiload();
    void append(std::unique_ptr<Combination> LC, const std::string& title);
private:
    void insertHeader();
    int _ULS{ULS_LC_START};
    int _SLS{SLS_LC_START};
};

#endif