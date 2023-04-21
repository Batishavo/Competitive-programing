#include <bits/stdc++.h>

using namespace std;

int a[5],
    b[5];

bool flag = false;

int main()
{

    for (int i = 1; i <= 3; i++)
    {
        cin >> a[i] >> b[i];
    }

    if (
        (a[2] + a[3] <= a[1] && b[2] <= b[1] && b[3] <= b[1]) ||
        (a[2] + b[3] <= a[1] && a[3] <= b[1] && b[2] <= b[1]) ||
        (b[2] + a[3] <= a[1] && b[3] <= b[1] && a[2] <= b[1]) ||
        (b[2] + b[3] <= a[1] && a[2] <= b[1] && a[3] <= b[1]) ||
        (a[2] + a[3] <= b[1] && b[3] <= a[1] && b[2] <= a[1]) ||
        (a[2] + b[3] <= b[1] && a[3] <= a[1] && b[2] <= a[1]) ||
        (b[2] + a[3] <= b[1] && b[3] <= a[1] && a[2] <= a[1]) ||
        (b[2] + b[3] <= b[1] && a[2] <= a[1] && a[3] <= a[1]))
    {
        flag = true;
    }

    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}