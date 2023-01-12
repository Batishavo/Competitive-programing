#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int n,
    aux,
    mayor = 0,
    cont,
    px[limit],
    position[limit];

bool use[limit];

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        mayor = max(mayor, aux);
        if (!use[aux])
        {
            use[aux] = 1;
            px[aux] = 0;
        }
        else
        {
            if (px[aux] == 0 || px[aux] == i - position[aux])
            {
                px[aux]=i - position[aux];
            }
            else
            {
                px[aux] = -1;
            }
        }
        position[aux] = i;
    }
    for (int i = 1; i <= mayor; i++)
    {
        if (px[i] != -1 && use[i])
        {
            cont++;
        }
    }
    cout << cont << endl;
    for (int i = 1; i <= mayor; i++)
    {
        if (px[i] != -1 && use[i])
        {
            printf("%d %d\n", i, px[i]);
        }
    }
    return 0;
}