#include <bits/stdc++.h>

using namespace std;

int t,
    n,
    m;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {

        cin >> n >> m;
        n /= 3;
        m /= 3;
        if (n == 0 && m == 0)
        {
            cout << "1" << endl;
        }
        else if (n == 0)
        {
            cout << m << endl;
        }
        else if (m == 0)
        {
            cout << n << endl;
        }
        else
        {
            cout << n * m << endl;
        }
    }

    return 0;
}