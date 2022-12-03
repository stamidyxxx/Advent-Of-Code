#include <cstdio>
#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <map>
#include "input.h"
using namespace std;

int main ()
{
    auto input = m_input.readfilelines("input_day3.txt");
    // part 1
    std::map<char, int> firstcompartment;
    std::map<char, int> secondcompartment;
    // part 2
    std::map<char, int> firstseg;
    std::map<char, int> secondseg;
    std::map<char, int> thirdseg;


    int ret = 0;

    int part;
    do 
    {
        cout << "Which part? \n";
        cin >> part;

    }while(part != 1 && part != 2);

    for (int j = 0; j < input.size(); ++j)
    {
        if (part == 1)
        {
            firstcompartment.clear();
            secondcompartment.clear();

            auto in = input[j];
            for (int i = 0; i < in.length(); ++i)
            {
                auto ch = in[i];
                if (i < (in.length() / 2))
                    firstcompartment[ch]++;
                else
                    secondcompartment[ch]++;
            }
            for (const auto& [ch, val] : firstcompartment)
            {
                if (secondcompartment[ch] != 0)
                {
                    if ((int)ch >= 65 && (int)ch <= 90)
                        ret += (int)ch - 38;
                    else if ((int)ch >= 97 && (int)ch <= 122)
                        ret += (int)ch - 96;
                    break;
                }
            }
        }
        else
        {
            auto in = input[j];
            auto seq = j % 3;

            // the inserting into array can be done cleaner, for example with arrays
            for (int i = 0; i < in.length(); ++i)
            {
                auto ch = in[i];
                if (seq == 0)
                    firstseg[ch]++;
                else if (seq == 1)
                    secondseg[ch]++;
                else if (seq == 2)
                    thirdseg[ch]++;
            }

            if (seq == 3 - 1) // last in the group
            {     
                for (const auto& [ch, val] : firstseg)
                {
                    if (secondseg[ch] != 0 && thirdseg[ch] != 0)
                    {
                        if ((int)ch >= 65 && (int)ch <= 90)
                            ret += (int)ch - 38;
                        else if ((int)ch >= 97 && (int)ch <= 122)
                            ret += (int)ch - 96;
                        break;
                    }
                }

                firstseg.clear();
                secondseg.clear();
                thirdseg.clear();
            }
        }
    }
    cout << "The sum of the priorities of those item types is: " << ret << "\n";

    system("pause");
}