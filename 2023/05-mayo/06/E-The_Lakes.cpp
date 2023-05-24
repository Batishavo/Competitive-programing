#include <bits/stdc++.h>

using namespace std;

//const int limit = 10e3 + 10;

int t,
    n,
    m,
    mat[1010][1010],
    memo[1010][1010],
    mov_i[10] = {1, 0, -1, 0},
    mov_j[10] = {0, 1, 0, -1};

long long mayor;

void clean()
{

    mayor = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            memo[i][j] = 0;
        }
    }
}

void bfs(int y, int x)
{
    long long suma = mat[y][x];

    queue<pair<int, int>> q;
    q.push({y, x});
    while (!q.empty())
    {
        pair<int, int> actual = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {

            int pi = actual.first + mov_i[k],
                pj = actual.second + mov_j[k];

            if (pi >= 0 && pi < n && pj >= 0 && pj < m &&
                mat[pi][pj] != 0 && memo[pi][pj] == 0)
            {
                memo[pi][pj] = 1;
                suma += mat[pi][pj];
                q.push({pi, pj});
            }
        }
    }

    mayor = max(mayor, suma);
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {

        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &mat[i][j]);
            }
        }
        // cout<<"---"<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != 0 && memo[i][j] == 0)
                {
                    memo[i][j] = 1;
                    bfs(i, j);
                }
            }
        }
        printf("%lld\n", mayor);
        clean();
    }

    return 0;
}