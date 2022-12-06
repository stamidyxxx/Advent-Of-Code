#include <cstdio>
#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "input.h"
using namespace std;

// can be made easier probably
bool unique_chars(string str)
{
    sort(str.begin(), str.end());
 
    for (int i = 0; i < str.length()-1; i++) 
        if (str[i] == str[i + 1]) 
            return false;

    return true;
}
 
int main()
{
    auto input = m_input.reafileasstring("input_day6.txt");

    int part;
    do 
    {
        cout << "Which part? \n";
        cin >> part;

    }while(part != 1 && part != 2);

    int ret = 0;
    int skip = 0;
    if (part == 1)
        skip = 4;
    else
        skip = 14;
        
    for (int i = 0; i < input.size() - skip; ++i) // ignore the last *skip* becuase we scan for + *skip*
    {
        auto chars = input.substr(i, skip);
        if (unique_chars(chars))
        {
            ret = i + skip;
            break;
        }
    }

    cout << ret << endl;

    system("pause");
}