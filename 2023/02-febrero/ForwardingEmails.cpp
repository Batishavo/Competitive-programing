#include <bits/stdc++.h>

using namespace std;

const int limit = 5e5 + 10;

int t,
    n,
    u,
    v,
    last,
    cont = 1,
    arr[limit],
    memo[limit],
    mark[limit];

queue<int> nums;

int dfs(int pos)
{
    last = pos;
    if (memo[pos] != 0)
    {
        return memo[pos];
    }
    if (mark[pos] == 1)
    {
        return 0;
    }
    nums.push(pos);
    mark[pos] = 1;
    return dfs(arr[pos]) + 1;
}

void clean()
{
    for (int i = 1; i <= n; i++)
    {
        mark[i] = 0;
        memo[i] = 0;
    }
}
void marcar(int aux)
{
    while (!nums.empty())
    {
        if (nums.front() == last)
        {
            while (!nums.empty())
            {
                memo[nums.front()] = aux;
                nums.pop();
            }
            return;
        }
        memo[nums.front()] = aux;
        nums.pop();
        aux--;
    }
}
int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    cin >> t;
    while (t--)
    {

        int mayor = 0,
            num = 0;
        cin >> n;
        clean();
        for (int i = 1; i <= n; i++)
        {
            cin >> u >> v;
            arr[u] = v;
        }
        for (int i = 1; i <= n; i++)
        {
            if (mark[i] == 0)
            {
                int aux = dfs(i);

                marcar(aux);

                if (aux > mayor)
                {
                    mayor = aux;
                    num = i;
                }
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << "++";
        //     cout << memo[i] << endl;
        // }
        // cout << num << endl;
        printf("Case %d: %d\n", cont++, num);
    }

    return 0;
}