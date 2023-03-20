#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int n,
    m,
    l,
    r,
    q;

long long arr[limit],
    r1[limit],
    r2[limit];

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        r1[i] = arr[i] + r1[i - 1];
    }
    sort(arr, arr + n + 1);
    for (int i = 1; i <= n; i++)
    {
        r2[i] = arr[i] + r2[i - 1];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> q >> l >> r;
        if (q == 1)
        {
            cout << r1[r] - r1[l - 1] << endl;
        }
        else
        {
            cout << r2[r] - r2[l - 1] << endl;
        }
    }

    return 0;
}