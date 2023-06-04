#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <fstream>
#include <limits>
#include <algorithm>

#include <locale>  //convert wstring to string
#include <codecvt> //convert wstring to string

template<class T>
class ParseInput
{
public:    
    void readFile(const std::string& filename)
    {    
    std::wifstream readFile;
    readFile.open(filename);
    if (readFile.is_open()) 
    {
        readFile.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); //ignore first line of the file
        std::wstring line;
        while (std::getline(readFile, line)) 
        {
            std::string string_line = convert_to_string(line);
            string_line.erase(std::remove(string_line.begin(), string_line.end(), '"'), string_line.end());
            lines.push_back(string_line);
        }
    }
    readFile.close();
    }

    T returnContent() const
    {
        return lines;
    }

private:
    T lines;   //std::vector<std::wstring> or std::deque<std::wstring>

    std::string convert_to_string(std::wstring wstring_to_convert)
    {
    using convert_type = std::codecvt_utf8<wchar_t>; //setup converter
    std::wstring_convert<convert_type, wchar_t> converter;

    //use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
    std::string converted_str = converter.to_bytes( wstring_to_convert );

    return converted_str; 
    }
};

#endif
