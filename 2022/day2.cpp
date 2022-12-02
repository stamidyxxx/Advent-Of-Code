#include <cstdio>
#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include "input.h"
using namespace std;

enum e_choice : int
{
    CHOICE_NONE,
    CHOICE_ROCK,
    CHOICE_PAPER,
    CHOICE_SCISSORS,

    CHOICE_WIN,
    CHOICE_LOSS,
    CHOICE_DRAW
};

int main()
{
    auto input = m_input.readfilelines("input_day2.txt");

    int part;
    do 
    {
        cout << "Which part? \n";
        cin >> part;

    }while(part != 1 && part != 2);

    int points = 0;     
    for (auto in : input)
    {
        string sep;
        stringstream ss(in);

        int enemy, our;
        int i = 0;
        while (getline(ss, sep, ' ')) 
        {  
            if (part == 1)
            {
                if (i == 0)
                {
                    if (sep == "A")
                        enemy = CHOICE_ROCK;
                    else if (sep == "B")
                        enemy = CHOICE_PAPER;
                    else if (sep == "C")
                        enemy = CHOICE_SCISSORS;
                }
                else
                {
                    if (sep == "X")
                        our = CHOICE_ROCK;
                    else if (sep == "Y")
                        our = CHOICE_PAPER;
                    else if (sep == "Z")
                        our = CHOICE_SCISSORS;
                }
            }
            else
            {
                if (i == 0)
                {
                    if (sep == "A")
                        enemy = CHOICE_ROCK;
                    else if (sep == "B")
                        enemy = CHOICE_PAPER;
                    else if (sep == "C")
                        enemy = CHOICE_SCISSORS;
                }
                else
                {
                    if (sep == "X")
                        our = CHOICE_LOSS;
                    else if (sep == "Y")
                        our = CHOICE_DRAW;
                    else if (sep == "Z")
                        our = CHOICE_WIN;
                }
            }

            ++i;
        }


        if (part == 1)
        {
            if (enemy == our) // draw
            {
                points += our + 3;
            }
            else if ((enemy == CHOICE_ROCK && our == CHOICE_PAPER) 
            || (enemy == CHOICE_PAPER && our == CHOICE_SCISSORS) 
            || (enemy == CHOICE_SCISSORS && our == CHOICE_ROCK)) // wins
            {
                points += our + 6;
            }
            else // loss
            {
                points += our;
            }
        }
        else // this can be done in a much shorter way
        {
            if (our == CHOICE_DRAW)
            {
                if (enemy == CHOICE_ROCK)
                    our = CHOICE_ROCK;
                else if (enemy == CHOICE_PAPER)
                    our = CHOICE_PAPER;
                else if (enemy == CHOICE_SCISSORS)
                    our = CHOICE_SCISSORS;

                points += 3;
            }
            else if (our == CHOICE_LOSS)
            {
                if (enemy == CHOICE_ROCK)
                    our = CHOICE_SCISSORS;
                else if (enemy == CHOICE_PAPER)
                    our = CHOICE_ROCK;
                else if (enemy == CHOICE_SCISSORS)
                    our = CHOICE_PAPER;
            } 
            else if (our == CHOICE_WIN)
            {
                if (enemy == CHOICE_ROCK)
                    our = CHOICE_PAPER;
                else if (enemy == CHOICE_PAPER)
                    our = CHOICE_SCISSORS;
                else if (enemy == CHOICE_SCISSORS)
                    our = CHOICE_ROCK;

                points += 6;
            }

            points += our;
        }
    }

    cout << "The points are: " << points << "\n";

    system("pause");
}
