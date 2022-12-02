#pragma once
#include <cstdio>
#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include <string>
using namespace std;

class c_input
{
public:
    std::vector<std::string> readfilelines(const std::string& fileName);
    std::string reafileasstring(const std::string& fileName);
};

extern c_input m_input;