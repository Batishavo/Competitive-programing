#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int n,
    p1 = 0,
    p2 = 0,
    arr1[limit],
    arr2[limit];

bool memo1[limit],
    memo2[limit];

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {

        cin >> arr1[i] >> arr2[i];
    }

    while (p1 + p2 < n)
    {
        if (arr1[p1] < arr2[p2])
        {
            memo1[p1++] = 1;
        }
        else
        {
            memo2[p2++] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            cout << "1";
        }
        else
        {
            cout << memo1[i];
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            cout << "1";
        }
        else
        {
            cout << memo2[i];
        }
    }
    return 0;
}
