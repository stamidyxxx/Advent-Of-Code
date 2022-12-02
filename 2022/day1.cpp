#include <cstdio>
#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include <string>
#include "input.h"
using namespace std;
int main()
{
     std::vector<std::string> input = m_input.readfilelines("input_day1.txt");
     int drr[400] = {};
     std::vector<int> deers;
     deers.reserve(400);

     int dr = 1;
     for (int i = 0; i < input.size(); ++i)
     {
         auto str = input[i];
         if (str.empty())
         {
             dr++;
             continue;
         }
         auto val = std::stoi(str.c_str());
         drr[dr] += val;
     }

     int idx = 1;
     while (drr[idx] != 0)
     {
         deers.push_back(drr[idx]);
         ++idx;
     }

    int part;
    do 
    {
        cout << "Which part? \n";
        cin >> part;

    }while(part != 1 && part != 2);

    if (part == 1)
    {
        int highestcal = 0;
        idx = 0;
        for (auto& d : deers)
        {
            if (d > highestcal)
            {
                highestcal = d;
            }
            ++idx;
        }

        cout << "The Elf with the highest calories has " << highestcal << " calories \n";
    }
    // pretty ugly, i did it fast :D
    else if (part == 2)
    {
        int ret = 0;
        int highestelf;
        int highestcal = -10;
        idx = 0;
        for (auto& d : deers)
        {
            if (d > highestcal)
            {
                highestcal = d;
                highestelf = idx;
            }
            ++idx;
        }
        ret += highestcal;
        deers.at(highestelf) = 0;


        highestelf = 0;
        highestcal = -10;
        idx = 0;
        for (auto& d : deers)
        {
            if (d > highestcal)
            {
                highestcal = d;
                highestelf = idx;
            }
            ++idx;
        }
        ret += highestcal;
        deers.at(highestelf) = 0;


        highestelf = 0;
        highestcal = -10;
        idx = 0;
        for (auto& d : deers)
        {
            if (d > highestcal)
            {
                highestcal = d;
                highestelf = idx;
            }
            ++idx;
        }
        ret += highestcal;
        deers.at(highestelf) = 0;

        cout << "The Top 3 Evles have a combined calorie amount of " << ret << "\n";
    }

    system("pause");
}