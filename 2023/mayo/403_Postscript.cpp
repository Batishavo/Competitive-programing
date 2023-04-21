#include <bits/stdc++.h>

using namespace std;

const int paper_grid = 60;

string command,
    arg1,
    arg4;

int arg2,
    arg3;

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
}
void init_map()
{
    c5[' '] = {
        {'.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.'}};
    c5['A'] = {
        {'.', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '*', '*', '*', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'}};
    c5['B'] = {
        {'*', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '*', '*', '*', '.', '.'}};
    c5['C'] = {
        {'.', '*', '*', '*', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'.', '*', '*', '*', '*', '.'}};
    c5['D'] = {
        {'*', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '*', '*', '*', '.', '.'}};
    c5['E'] = {
        {'*', '*', '*', '*', '*', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'*', '*', '*', '.', '.', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'*', '*', '*', '*', '*', '.'}};
    c5['F'] = {
        {'*', '*', '*', '*', '*', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'*', '*', '*', '.', '.', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'*', '.', '.', '.', '.', '.'}};
    c5['G'] = {
        {'.', '*', '*', '*', '*', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'*', '.', '.', '*', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'.', '*', '*', '*', '.', '.'}};
    c5['H'] = {
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '*', '*', '*', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'}};
    c5['I'] = {
        {'*', '*', '*', '*', '*', '.'},
        {'.', '.', '*', '.', '.', '.'},
        {'.', '.', '*', '.', '.', '.'},
        {'.', '.', '*', '.', '.', '.'},
        {'*', '*', '*', '*', '*', '.'}};
    c5['J'] = {
        {'.', '.', '*', '*', '*', '.'},
        {'.', '.', '.', '*', '.', '.'},
        {'.', '.', '.', '*', '.', '.'},
        {'*', '.', '.', '*', '.', '.'},
        {'.', '*', '*', '.', '.', '.'}};
    c5['K'] = {
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '*', '.', '.'},
        {'*', '*', '*', '.', '.', '.'},
        {'*', '.', '.', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'}};
    c5['L'] = {
        {'*', '.', '.', '.', '.', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'*', '*', '*', '*', '*', '.'}};
    c5['M'] = {
        {'*', '.', '.', '.', '*', '.'},
        {'*', '*', '.', '*', '*', '.'},
        {'*', '.', '*', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'}};
    c5['N'] = {
        {'*', '.', '.', '.', '*', '.'},
        {'*', '*', '.', '.', '*', '.'},
        {'*', '.', '*', '.', '*', '.'},
        {'*', '.', '.', '*', '*', '.'},
        {'*', '.', '.', '.', '*', '.'}};
    c5['O'] = {
        {'.', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'.', '*', '*', '*', '.', '.'}};
    c5['P'] = {
        {'*', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'*', '.', '.', '.', '.', '.'}};
    c5['Q'] = {
        {'.', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '*', '*', '.'},
        {'.', '*', '*', '*', '*', '.'}};
    c5['R'] = {
        {'*', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '*', '*', '*', '.', '.'},
        {'*', '.', '.', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'}};
    c5['S'] = {
        {'.', '*', '*', '*', '*', '.'},
        {'*', '.', '.', '.', '.', '.'},
        {'.', '*', '*', '*', '.', '.'},
        {'.', '.', '.', '.', '*', '.'},
        {'*', '*', '*', '*', '.', '.'}};
    c5['T'] = {
        {'*', '*', '*', '*', '*', '.'},
        {'*', '.', '*', '.', '*', '.'},
        {'.', '.', '*', '.', '.', '.'},
        {'.', '.', '*', '.', '.', '.'},
        {'.', '*', '*', '*', '.', '.'}};
    c5['U'] = {
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'.', '*', '*', '*', '.', '.'}};
    c5['V'] = {
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'.', '*', '.', '*', '.', '.'},
        {'.', '*', '.', '*', '.', '.'},
        {'.', '.', '*', '.', '.', '.'}};
    c5['W'] = {
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '*', '.'},
        {'*', '.', '*', '.', '*', '.'},
        {'*', '*', '.', '*', '*', '.'},
        {'*', '.', '.', '.', '*', '.'}};
    c5['X'] = {
        {'*', '.', '.', '.', '*', '.'},
        {'.', '*', '.', '*', '.', '.'},
        {'.', '.', '*', '.', '.', '.'},
        {'.', '*', '.', '*', '.', '.'},
        {'*', '.', '.', '.', '*', '.'}};
    c5['Y'] = {
        {'*', '.', '.', '.', '*', '.'},
        {'.', '*', '.', '*', '.', '.'},
        {'.', '.', '*', '.', '.', '.'},
        {'.', '.', '*', '.', '.', '.'},
        {'.', '.', '*', '.', '.', '.'}};
    c5['Z'] = {
        {'*', '*', '*', '*', '*', '.'},
        {'.', '.', '.', '*', '.', '.'},
        {'.', '.', '*', '.', '.', '.'},
        {'.', '*', '.', '.', '.', '.'},
        {'*', '*', '*', '*', '*', '.'}};
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
    cout << endl;
    for (int i = 0; i < paper_grid; i++)
    {
        cout << "-";
    }
    cout << endl
         << endl;
    ;
}

void print_c1(int inicio, int fin, int paso, int cad_pos)
{

    for (int i = inicio; i != fin; i += paso)
    {
        if (i >= paper_grid || i <= -1 || cad_pos >= arg4.size() || cad_pos < 0)
        {
            break;
        }
        if (arg4[cad_pos] != ' ')
        {
            paper[arg2][i] = arg4[cad_pos];
        }
        cad_pos += paso;
    }
}

void print_leter(char caracter, int i, int j)
{
    int fin_i = i + 5,
        fin_j = j + 6,
        pi = 0,
        pj = 0;

    for (i; i < fin_i; i++)
    {
        j = fin_j - 6;
        pj = 0;
        for (j; j < fin_j; j++)
        {
            if (i < 0 || i >= paper_grid || j < 0 || j >= paper_grid)
            {
                continue;
            }
            if (paper[i][j]=='.')
                paper[i][j] = c5[caracter][pi][pj];
            // cout<<i<<" "<<j<<endl;
            pj++;
        }
        // cout<<endl;
        pi++;
        // cout << "--------" << endl;
    }
}

void print_c2(int i, int j, int paso_j, int cad_pos, int cad_paso)
{
    for (j;; j += paso_j)
    {
        if (j <= -6 || j >= paper_grid || cad_pos < 0 || cad_pos >= arg4.size())
        {
            break;
        }
        // cout << arg4[cad_pos] << " " << i << " " << j << endl;
        print_leter(arg4[cad_pos], i, j);
        cad_pos += cad_paso;
    }
    // cout << endl;
}

void write_paper()
{
    switch (command[1])
    {
    case 'P':
        if (arg1 == "C1")
        {
            print_c1(arg3 - 1, arg3 + arg4.size(), 1, 0);
        }
        else
        {
            print_c2(arg2, arg3 - 1, 6, 0, 1);
        }
        break;

    case 'L':
        if (arg1 == "C1")
        {
            print_c1(0, arg4.length(), 1, 0);
        }
        else
        {
            print_c2(arg2, 0, 6, 0, 1);
        }
        break;

    case 'R':
        if (arg1 == "C1")
        {
            print_c1(
                paper_grid - 1,
                paper_grid - int(arg4.length() + 1),
                -1,
                arg4.length() - 1);
        }
        else
        {
            print_c2(arg2, paper_grid - 6, -6, arg4.size() - 1, -1);
        }
        break;

    default:
        if (arg1 == "C1")
        {
            int num = arg4.size() / 2;
            // cout<<arg4[num + 3]<<endl;
            if (arg4.size() % 2 == 0)
            {

                print_c1(30, 30 + num, 1, num);
                print_c1(29, 29 - num, -1, num - 1);
            }
            else
            {
                // cout<<"--"<<arg4<<endl;
                if (arg4[num + 1] != ' ')
                {

                    paper[arg2][31] = arg4[num + 1];
                }
                if (arg4.size() > 1)
                {
                    print_c1(32, 32 + num - 1, 1, num + 2);
                    print_c1(30, 30 - num - 1, -1, num);
                }
            }
        }
        else
        {
            if (arg4.size() % 2 == 0)
            {
                // cout<<"X"<<endl;
                print_c2(arg2, 30, 6, arg4.size() / 2, 1);
                print_c2(arg2, 30 - 6, -6, arg4.size() / 2 - 1, -1);
            }
            else
            {
                int cad_pos = arg4.size() / 2;
                print_leter(arg4[cad_pos], arg2, 27);
                print_c2(arg2, 33, 6, arg4.size() / 2 + 1, 1);
                print_c2(arg2, 27 - 6, -6, arg4.size() / 2 - 1, -1);
            }
        }
        break;
    }
}
int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    init_map();
    init();
    while (cin >> command)
    {

        if (command == ".EOP")
        {
            print_paper();
            init();
            continue;
        }
        cin >> arg1 >> arg2;
        if (command == ".P")
        {
            cin >> arg3;
        }
        getline(cin, arg4);
        arg4 = arg4.substr(2, arg4.size() - 3);
        arg2--;
        // cout << arg4 << endl;
        write_paper();
    }
    // cout<<"XXXX";
    return 0;
}