#include <bits/stdc++.h>

using namespace std;

const int paper_grid = 60;

string command,
    arg1,
    arg2,
    arg3,
    arg4;

char paper[70][70];

map<char, vector<vector<char>>> c5;

void init()
{
    for (int i = 0; i < paper_grid; i++)
    {
        for (int j = 0; j < paper_grid; j++)
        {
            paper[i][j] = '.';
        }
    }
    c5['A'] = {
        {'.', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '*', '*', '*', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'}};
}

void write_paper()
{
}

void print_paper()
{
    for (int i = 0; i < paper_grid; i++)
    {
        for (int j = 0; j < paper_grid; j++)
        {
            cout << paper[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < paper_grid; i++)
    {
        cout << "-";
    }
    cout << endl;
}

int main()
{

    while (cin >> command)
    {
        if (command == ".EOP")
        {
            break;
        }
        cin >> arg1 >> arg2;
        if (command == ".P")
        {
            cin >> arg3;
        }
        cin >> arg4;
        write_paper();
    }
    print_paper();

    return 0;
}