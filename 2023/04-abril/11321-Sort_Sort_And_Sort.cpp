#include <bits/stdc++.h>

using namespace std;

const int limit = 10e4 + 10;

int m,
    n,
    arr[limit];

bool comp(int a, int b)
{

    if (a % m != b % m)
    {
        return a % m < b % m;
    }
    else if (a & 1)
    {
        if(b & 1){
            return a > b ;
        }
        return true;
    }
    else
    {
        if (b & 1)
        {
            return false;
        }
    }

    return a < b;
}

int main()
{
    /*freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);*/
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n, comp);
        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << endl;
        }
    }
    cout << "0 0" << endl;

    return 0;
}