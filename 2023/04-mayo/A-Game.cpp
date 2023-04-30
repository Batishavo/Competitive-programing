#include <bits/stdc++.h>

using namespace std;

const int limit = 10e3 + 10;

int n,
    tmp,
    arr[limit];

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    tmp = (n % 2 == 0) ? 1 : 0;
    cout << arr[n / 2 - tmp] << endl;

    return 0;
}