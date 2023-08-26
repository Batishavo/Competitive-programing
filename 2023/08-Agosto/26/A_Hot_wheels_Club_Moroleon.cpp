#include <bits/stdc++.h>

using namespace std;

int order[5][5] = {
    {0, 1, 0},
    {4, 3, 2},
    {0, 1, 0}};

int res[10];

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;

    string trash;
    string name;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        getline(cin, trash);
        getline(cin, name);

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                char c;
                cin >> c;
                //cout << c;
                if (c == '#')
                {
                    res[order[row][col]]++;
                }
            }
            //cout << endl;
        }
        //cout << name << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}