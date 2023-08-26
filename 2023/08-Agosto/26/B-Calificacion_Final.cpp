#include <bits/stdc++.h>

using namespace std;

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int acumulado = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {

        int a, b;

        cin >> a >> b;

        acumulado += a * b / 10;

        for (int j = 0; j < a; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    if (acumulado / 10 >= 6)
    {
        cout << acumulado / 10 << endl;
        cout << ":)" << endl;
    }
    else
    {
        cout << 0 << endl;
        cout << ":(" << endl;
    }

    return 0;
}