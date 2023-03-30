#include <bits/stdc++.h>

using namespace std;

const int limit = 1005;

int n, k, num_pairs;
int connections[limit];

int main()
{
    cin >> n >> k;

    num_pairs = n*(n-1)/2;
    if (n <= 2 || k > num_pairs / n)
    {
        cout << "-1" << endl;
    }
    else
    {
        int total = k * n;
        int next_node = 2;
        cout<<total << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (next_node > n) {
                    next_node = 1;
                }
                cout << i << " " << next_node << endl;
                connections[i]++;
                next_node++;
            }
        }
    }

    return 0;
}