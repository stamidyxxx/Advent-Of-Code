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
#include <queue>
#include "input.h"
using namespace std;

// not very proud of this, a lot is copied, since i have 0 experience with node problems like these.
struct Folder {
    string m_name;
    int m_size;
    Folder* m_previous;
    vector<Folder*> m_children;

    Folder() {}

    Folder(string name, int size, Folder* prev) 
    {
        this->m_name = name;
        this->m_size = size;
        this->m_previous = prev;
    }
};

void folder_size(Folder* root) {
    if(root == NULL) return;

    int sum = 0;

    for(auto& child: root->m_children) {   
        folder_size(child);
        root->m_size += child->m_size; 
    }
}

int calc_total_folder_size(Folder* root) {
    int ret = 0;
    queue<Folder*> Q;
    Q.push(root);

    while(!Q.empty())
    {
        Folder* tmp = Q.front();
        Q.pop();

        if(tmp->m_size <= 100000) 
            ret += tmp->m_size;
        for(auto& child : tmp->m_children)
            Q.push(child);
    }

    return ret;
}

vector<int> get_all_folders(Folder* root) 
{
    queue<Folder*> Q;
    vector<int> V;
    Q.push(root);

    while(!Q.empty()) 
    {
        Folder* tmp = Q.front();
        Q.pop();

        V.push_back(tmp->m_size);
        for(auto& child : tmp->m_children)
            Q.push(child);
    }

    return V;
}

int main()
{
    auto input = m_input.readfilelines("input_day7.txt");

    auto currentdir = new Folder("/", 0, 0); // starting, our currentdir is the root dir
    Folder* head = currentdir;
    Folder* head2 = currentdir;

    int part;
    do 
    {
        cout << "Which part? \n";
        cin >> part;

    }while(part != 1 && part != 2);

    for (auto& in : input)
    {
        if (in[0] == '$') // check if we executed a command
        {
            if (in[2] == 'c') // check if the executed command is 'cd'
            {
                if (in[5] != '/') // if we have the root directory dont do anything, since we reset it back
                {
                    char foldername[50];
                    sscanf(in.c_str(), "$ cd %s", foldername);

                    if (foldername[0] == '.') // go back
                        currentdir = currentdir->m_previous;
                    else
                    {
                        // loop throught all the folder, check if we already encountered that folder, if not we still created a new one
                        Folder* newfolder = NULL;
                        for(auto& childfolder : currentdir->m_children)
                            if(childfolder->m_name == foldername)
                                newfolder = childfolder;

                        currentdir = newfolder;
                    }
                }
            }
        }
        else // we didnt execute a command, the text is a result of ls, so read values
        {
            if ((int)in[0] >= 48 && (int)in[0] <= 57) // check if the first char is a digit
            {
                int value = 0;
                char tmp[50];
                sscanf(in.c_str(), "%d %s", &value, tmp); // read the value and add it to the total

                currentdir->m_size += value;    
            }
            else // its not a number!
            {
                char foldername[50];
                sscanf(in.c_str(), "dir %s", foldername);

                auto newfolder = new Folder(foldername, 0, currentdir); // create a new dir with the previous dir as the root(current) dir
                currentdir->m_children.push_back(newfolder); // input the new child :)
            }
        }
    }

    folder_size(head);

    if (part == 1)
    {
        cout << calc_total_folder_size(head2) << endl;
    }
    else
    {
        int need = 30000000 - (70000000 - head2->m_size);
        vector<int> folders = get_all_folders(head2);
        sort(folders.begin(), folders.end());
     
        for (auto& folder : folders)
            if (folder >= need)
            {
                cout << folder << endl;
                break;
            }
    }
    system("pause");
}