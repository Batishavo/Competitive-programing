#include <bits/stdc++.h>

using namespace std;

const int limit = 10010;

int L,
    U,
    R,
    cont = 1,
    memo[limit],
    mark[limit],
    arr[15];

queue<int> q;

int suma(int num1, int num2)
{

    if (num1 + num2 > 9999)
    {
        return num1 + num2 - 10000;
    }
    return num1 + num2;
}

bool bfs(int inicial)
{
    mark[inicial] = 1;
    q.push(inicial);

    while (!q.empty())
    {

        int actual = q.front();
        q.pop();
        if (actual == U)
        {
            return true;
        }
        for (int i = 0; i < R; i++)
        {
            int pos = suma(actual, arr[i]);
            if (mark[pos] == 0)
            {
                mark[pos] = 1;
                memo[pos] = memo[actual] + 1;
                q.push(pos);
            }
        }
    }

    return false;
}

void clean()
{
    for (int i = 0; i <= 9999; i++)
    {
        memo[i] = 0;
        mark[i] = 0;
    }
    while (!q.empty())
    {
        q.pop();
    }
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    
    while (true)
    {
        cin >> L >> U >> R;
        if (L == 0 && U == 0 && R == 0)
        {
            return 0;
        }
        for (int i = 0; i < R; i++)
        {
            cin >> arr[i];
        }
        clean();
        if (bfs(L))
        {
            printf("Case %d: %d\n", cont++, memo[U]);
        }
        else
        {
            printf("Case %d: Permanently Locked\n", cont++);
        }
    }

    return 0;
}