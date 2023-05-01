#include <bits/stdc++.h>

using namespace std;

int n,
    bucket[110];

bool flag = true;

int main()
{
    /*freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);*/
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        flag = true;
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            bucket[aux]++;
        }
        for (int i = 1; i <= 100; i++)
        {
            if (bucket[i] != 0)
            {
                for (int j = 0; j < bucket[i]; j++)
                {
                    if (flag)
                    {
                        flag = false;
                    }
                    else
                    {
                        cout << " ";
                    }
                    cout << i;
                }
                bucket[i] = 0;
            }
        }
        cout << endl;
    }

    return 0;
}