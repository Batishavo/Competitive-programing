#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int n,
    m,
    mayor,
    cont = 1,
    dis[405][405],
    memo[150],
    p[405][405];

bool flag = 1;

void printPath(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!memo[i])
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (!memo[j])
                continue;
            if (i == j)
                continue;
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        memo[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = i;
            if (i == j)
                continue;
            dis[i][j] = inf;
        }
    }
}

void floyWarshall(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!memo[i])
                continue;
            for (int j = 1; j <= n; j++)
            {
                if (!memo[j])
                    continue;
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
    //printPath(mayor);
}
float suma(int n)
{

    int cont = 0;
    float sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!memo[i])
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (!memo[j])
                continue;
            if (i == j)
                continue;
            sum += (float)(dis[i][j]);
            cont++;
        }
    }
    return sum / ((float)cont);
}
int main()
{
    init(100);
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            if (!flag)
            {
                return 0;
            }
            else
            {
                floyWarshall(mayor);
                printf("Case %d: average length between pages = %.3f clicks\n", cont++, suma(mayor));
                init(mayor);
                mayor = 0;
            }
            flag = false;
        }
        else
        {
            dis[n][m] = 1;
            memo[n] = 1;
            memo[m] = 1;
            flag = true;
            mayor = max(mayor, max(n, m));
        }
    }

    return 0;
}