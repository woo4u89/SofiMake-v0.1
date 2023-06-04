/**********************************************
 * SofiMake - import load combinations from
 * Autodesk Robot to Sofistik Teddy (Sofiload)
 *         Created on: June 04, 2023
 *          Author: Maciej Zieliński
 **********************************************/

#include <iostream>
#include <memory>
#include <deque>
#include <string>

#include "parse.h"
#include "combination.h"
#include "loadcase.h"
#include "sofiload.h"


int main()
{

const std::string filename = "komb_robot.csv"; //UTF-8 format

std::wcout << L"Wymagana nazwa pliku kombinacji programu Robot: komb_robot.csv" << std::endl;
std::wcout << "Wymagane kodowanie pliku komb_robot.csv: UTF8" << std::endl;
std::wcout << L"Format kombinacji: STA1*1.10 + STA2*1.30 + STA3*1.20 + EKSP1*1.20 + EKSP2*1.20" << std::endl;

auto parsefile = std::make_shared<ParseInput<std::vector<std::string>>>(); //std::vector or std::deque

parsefile->readFile(filename);
auto result = parsefile->returnContent(); //vector of type string
auto sofiload = std::make_shared<Sofiload>();

std::cout << std::endl; 

std::vector<std::unique_ptr<Combination>> allCombinations;

try {
    for (std::string& singleCombination : result)
    {
        allCombinations.push_back(std::make_unique<Combination>(singleCombination));
        sofiload->append(std::move(allCombinations.back()), singleCombination);
    }
    } 
catch (const std::exception& e) 
    {
    std::cerr << "Exception occurred: " << e.what() << std::endl;
    }
}
