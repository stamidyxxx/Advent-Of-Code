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

int main()
{
    auto input = m_input.readfilelines("input_day5.txt");
    string stacks[10];
    string ret;

    int part;
    do 
    {
        cout << "Which part? \n";
        cin >> part;

    }while(part != 1 && part != 2);

    int idx = 0, start = 0;
    for (auto j = 0; j < input.size(); ++j)
    {
        idx = 0;
        auto in = input[j];
        if (isdigit(in[1]))
            break;

        for (int i = 1; i < in.length(); i += 4)
        {
            auto ch = in[i];
            if (isalpha(ch))
            {
                stacks[idx] += ch;
            }
            idx++;
        }
    }

    for (auto& stack : stacks)
        reverse(stack.begin(), stack.end());

    int amount, from, to;

    for (auto j = 0; j < input.size(); ++j)
    {
        auto in = input[j];

        auto ret = sscanf(in.c_str(), "move %d from %d to %d", &amount, &from, &to);

        if (ret <= 0)
            continue;

        if (part == 1)
        {
            for (int i = 0; i < amount; ++i)
            {
                stacks[to - 1] += stacks[from - 1].back();
                stacks[from - 1].pop_back();
            }
        }
        else
        {
            stacks[to - 1] += stacks[from - 1].substr(stacks[from - 1].length() - amount);
            stacks[from - 1].erase(stacks[from - 1].length() - amount);

        }
    }

    for (auto& stack : stacks)
        ret += stack.back();

    cout << "Crates on top of each stack: " << ret << endl;
    system("pause");
}