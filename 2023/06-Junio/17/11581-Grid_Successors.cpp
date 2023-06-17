#include <bits/stdc++.h>

using namespace std;

int pi[5] = {-1, 1, 0, 0},
    pj[5] = {0, 0, -1, 1},
    t,
    answer = -1;

char mat[5][5];

bool only_cero()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat[i][j] != '0')
            {
                return false;
            }
        }
    }
    return true;
}

void sum()
{

    int aux[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            int cont = 0;

            for (int k = 0; k < 4; k++)
            {

                int x = i + pi[k],
                    y = j + pj[k];

                if (x >= 0 && x < 3 && y >= 0 && y < 3)
                {
                    cont += mat[x][y]-'0';
                }
            }
            aux[i][j] = cont % 2;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = aux[i][j]+'0';
        }
    }
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> mat[i][j];
            }
        }

        while (!only_cero())
        {
            sum();
            answer++;
        }

        cout << answer << endl;
        answer=-1;
    }

    return 0;
}