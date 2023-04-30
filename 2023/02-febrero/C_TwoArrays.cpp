#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int limN = 2000;
const int limM = 40;

int n,
    m;

long long memo[limM][limN];

bool mark[limM][limN];

long long dp(int pos, int ant)
{

    if (pos == m * 2)
    {
        return 1;
    }
    if (mark[pos][ant])
    {
        return memo[pos][ant];
    }
    mark[pos][ant] = 1;
    int ini = ant;
    if (ini == 0)
        ini = 1;
    long long num = 0;
    for (int i = ini; i <= n; i++)
    {
        num += dp(pos + 1, i);
        num %= mod;
    }
    return memo[pos][ant] = num;
}

int main()
{

    cin >> n >> m;

    // cout << "--";
    cout << dp(0, 0) << endl;

    return 0;
}