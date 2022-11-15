#include <bits/stdc++.h>

using namespace std;

long long n, m;

int main()
{

    cin >> n >> m;

    long long mcd = (n * m) / __gcd(n, m),
        dasha = mcd / n,
        masha = mcd / m;

    if (n < m)
    {
        dasha--;
    }
    else
    {
        masha--;
    }

    if (masha == dasha)
    {
        cout << "Equal" << endl;
    }

    else if (dasha > masha)
    {
        cout << "Dasha" << endl;
    }
    else
    {
        cout << "Masha" << endl;
    }

    return 0;
}