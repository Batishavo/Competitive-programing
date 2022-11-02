#include <bits/stdc++.h>

using namespace std;

int n,
    m,
    tmp1,
    tmp2,
    mat[60][60],
    memo[60];

long long solution = 1;

void dfs(int num)
{
    for (int i = 1; i <= n; i++)
    {
        if (mat[i][num] == 1 && memo[i] == 0)
        {
            memo[i] = 1;
            solution *= 2;
            dfs(i);
        }
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;
        mat[tmp1][tmp2] = 1;
        mat[tmp2][tmp1] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (memo[i] == 0)
        {
            memo[i] = 1;
            dfs(i);
        }
    }

    cout << solution << endl;

    return 0;
}