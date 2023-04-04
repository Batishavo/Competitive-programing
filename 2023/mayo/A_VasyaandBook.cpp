#include <bits/stdc++.h>

using namespace std;

int t;

long long
    n,
    x,
    y,
    d;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    scanf("%d", &t);

    while (t--)
    {
        cin >> n >> x >> y >> d;
        long long num = -1;
        if (x == y)
        {
            cout << "0" << endl;
            continue;
        }
        else if (y == 1)
        {
            cout << ((x - 1) / d) + ((x - 1) % d == 0 ? 0 : 1) << endl;
            continue;
        }
        else if (y == n)
        {
            long long aux = n - x + 1;
            cout << ((aux - 1) / d) + ((aux - 1) % d == 0 ? 0 : 1) << endl;
            continue;
        }
        else if (abs(y - x) % d == 0)
        {
            cout << abs(y - x) / d << endl;
            continue;
        }

        if ((y - 1) % d == 0)
        {
            // cout<<"--1"<<endl;
            num = (y - 1) / d;
            num += ((x - 1) / d) + ((x - 1) % d == 0 ? 0 : 1);
        }
        if ((n - y) % d == 0)
        {
            // cout<<"--2"<<endl;
            long long aux = n - x + 1;
            aux = ((aux - 1) / d) + ((aux - 1) % d == 0 ? 0 : 1);
            aux += (n - y) / d;
            if (num == -1)
            {
                num = aux;
            }
            else
            {
                num = min(num, aux);
            }
        }

        cout << num << endl;
    }

    return 0;
}