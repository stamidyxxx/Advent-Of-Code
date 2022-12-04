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

int main()
{
    auto input = m_input.readfilelines("input_day4.txt");


    int part;
    do 
    {
        cout << "Which part? \n";
        cin >> part;

    }while(part != 1 && part != 2);

    int ret = 0;
    for (int j = 0; j < input.size(); ++j)
    {
        auto in = input[j];
        int nums[4] = {0,0,0,0};
        int idx = 0;

        for (int i = 0; i < in.length(); ++i)
        {
            auto ch = in[i];
             if (ch == ',' || ch == '-')
                idx++;
             else
                nums[idx] = nums[idx] * 10 + ch - '0'; // previous*10 + stoi
        }

        /*
        0 - start
        1 - end

        2 - start
        3 - end
        */
        if (part == 1) 
        {      
            if (nums[0]<=nums[2] && nums[3]<=nums[1] || nums[2]<=nums[0] && nums[1]<=nums[3])
                ret++;
        }
        else
        {
            if (!(nums[1] < nums[2] || nums[0] > nums[3]))
                ret++;
        }
    }
    if (part == 1)
        cout << "One range fully contains the other in "<< ret << " assignment\n";
    else
        cout << "The ranges overlap in " << ret << " assignments\n";
        
    system("pause");
}