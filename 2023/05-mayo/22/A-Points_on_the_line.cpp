#include <bits/stdc++.h>

using namespace std;

int n,
    m,
    arr[110],
    sum[110],
    sum2[110];

void sumar()
{

    for (int i = 1; i <= 100; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 100; i >= 1; i--)
    {
        sum2[i] = sum2[i + 1] + arr[i];
    }
}

int answer()
{

    int menor = INT_MAX;

    for (int i = 1; i <= 100; i++)
    {

        int pos = i + m;

        if (pos > 100)
        {
            pos = 100;
        }
        if (arr[i] != 0)
        {
            //cout << i << " " << pos << " " << n - (sum[pos] - sum[i - 1]) << endl;
            menor = min(menor, n - (sum[pos] - sum[i - 1]));
        }
    }

    for (int i = 100; i >= 1; i--)
    {
        int pos = i - m;

        if (pos < 1)
        {
            pos = 1;
        }

        if (arr[i] != 0)
        {
            //cout << i << " " << pos << " " << n - (sum2[pos] - sum2[i + 1]) << endl;
            menor = min(menor, n - (sum2[pos] - sum2[i + 1]));
        }
    }

    return menor;
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int aux;
        cin >> aux;
        arr[aux]++;
    }

    sumar();

    cout << answer() << endl;

    return 0;
}