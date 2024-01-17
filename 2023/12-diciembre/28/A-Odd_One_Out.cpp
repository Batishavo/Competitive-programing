#include <bits/stdc++.h>

using namespace std;

int diferentNumber(int a, int b, int c)
{

    if (a == b)
    {
        return c;
    }
    else if (a == c)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int n;

    cin >> n;

    while (n--)
    {
        int a, b, c;

        cin >> a >> b >> c;

        cout << diferentNumber(a, b, c)<<endl;
    }

    return 0;
}