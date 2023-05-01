#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

string cad;

int a,
    cant,
    memo[limit];

bool posible(int pos)
{
    int aux = pos + 1;
    for (int i = 0; i <= pos; i++)
    {
        if (cad[i] != 'a')
        {
            if (cad[i] != cad[aux])
            {
                return false;
            }
            aux++;
        }
    }
    return true;
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    cin >> cad;
    for (int i = 0; i < cad.size(); i++)
    {
        if (cad[i] == 'a')
        {
            a = i;
        }
        else
        {
            cant++;
        }
        memo[i] = cant;
    }

    bool flag = 0;
    int pos;
    for (int i = a; i < cad.size(); i++)
    {
        if (cant - memo[i] == memo[i])
        {
            //cout << i << endl;
            flag = posible(i);
            pos = i + 1;
            break;
        }
    }
    if (!flag)
    {
        cout << ":(" << endl;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            cout << cad[i];
        }
        cout << endl;
    }

    return 0;
}