#include <bits/stdc++.h>

using namespace std;

const int limit = 1005;

int n,
    k,
    arr[limit];

int main()
{

    cin >> n >> k;

    if (n <= 2)
    {
        cout << "-1" << endl;
    }
    else
    {
        int num = ((n - 1) * (n)) / 2,
            total = k * n,
            pos = 0,
            ini=0;

        if (k <= num / n)
        {
            cout << total << endl;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <=k; j++)
                {
                    int next = (i + j + 1) % n +1;
                    if (arr[i] < k)
                    {
                        arr[i]++;
                        cout << i << " " << next << endl;
                    }
                    else 
                    {
                        cout << next << " " << i << endl;
                        arr[next]++;
                    }
                }
            }
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}