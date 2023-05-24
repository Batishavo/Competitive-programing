#include <bits/stdc++.h>

using namespace std;

const int limit = 110;

int n,
    t,
    a[limit],
    b[limit];

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {

        cin >> n;

        bool flag = 1;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (
                (a[i] > a[n - 1] || b[i] > b[n - 1]) &&
                (a[i] > b[n - 1] || b[i] > a[n - 1]))
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}