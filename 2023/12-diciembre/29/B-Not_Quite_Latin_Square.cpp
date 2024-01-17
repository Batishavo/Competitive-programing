#include <bits/stdc++.h>

using namespace std;

string leters[5];

bool isPosible(char character, int i, int j)
{

    for (int x = 0; x < 3; x++)
    {
        if (leters[i][x] == character)
        {
            return false;
        }
    }
    for (int x = 0; x < 3; x++)
    {
        if (leters[x][j] == character)
        {
            return false;
        }
    }
    return true;
}

char misingCharacter()
{

    char misingCharacter[5] = {'A', 'B', 'C'};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (leters[i][j] == '?')
            {
                for (int x = 0; x < 3; x++)
                {
                    if (isPosible(misingCharacter[x], i, j))
                    {
                        return misingCharacter[x];
                    }
                }
            }
        }
    }
    return '-';
}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int t;

    scanf("%d", &t);

    while (t--)
    {

        for (int i = 0; i < 3; i++)
        {
            cin >> leters[i];
        }

        cout << misingCharacter() << endl;
    }

    return 0;
}