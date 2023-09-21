#include <bits/stdc++.h>

using namespace std;

const int limit = 30010;

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    long long dp[limit + 10];
    long long coins[4] = {5, 10, 25, 50};

    int query;

    for (int i = 0; i < limit; i++)
    {
        dp[i] = 1;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = coins[i]; j < limit; ++j)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    while (cin >> query)
    {
        if (dp[query] == 1)
        {
            printf("There is only %lld way to produce %d cents change.\n", dp[query], query);
        }
        else
        {
            printf("There are %lld ways to produce %d cents change.\n", dp[query], query);
        }
    }

    return 0;
}