#include "input.h"

std::vector<std::string> c_input::readfilelines(const std::string& fileName) 
{
     std::ifstream file(fileName, std::ios::in);
     std::string line;
     std::vector<std::string> lines;
     while(getline(file, line))
         lines.push_back(line);
     return lines;
}

std::string c_input::reafileasstring(const std::string& fileName) 
{
     std::ifstream file(fileName, std::ios::in);
     std::string line;
     std::string readString = "";
     while(getline(file, line))
         readString.append(line);
     return readString;
}

c_input m_input;