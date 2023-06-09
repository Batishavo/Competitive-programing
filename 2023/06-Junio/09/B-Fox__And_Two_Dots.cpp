#include <bits/stdc++.h>

using namespace std;

int n,
    m,
    pi[5] = {1, 0, -1, 0},
    pj[5] = {0, 1, 0, -1};

char mat[60][60];

bool memo[60][60];

bool clean()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            memo[i][j] = 0;
        }
    }
}

bool bfs(int y, int x, int y1, int x1)
{

    queue<pair<int, int>> q;

    q.push({y1, x1});

    memo[y1][x1] = 1;

    while (!q.empty())
    {
        pair<int, int> actual = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {

            int di = actual.first + pi[k],
                dj = actual.second + pj[k];

            if (di >= 0 && di < n && dj >= 0 && dj < m)
            {
                if (memo[di][dj] == 0 && mat[di][dj] == mat[y][x])
                {
                    memo[di][dj] = 1;
                    q.push({di, dj});
                }
            }
        }
    }

    for (int k = 0; k < 4; k++)
    {
        int x2 = x + pi[k],
            y2 = y + pj[k];
        
        if(x1==x2 && y1==y2){
            continue;
        }

        if(y2>=0 && y2<n && x2>=0 && x2<m && memo[y2][x2]==1){
            //cout<<x<<" "<<y<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<m;j++){
            //         cout<<memo[i][j];
            //     }
            //     cout<<endl;
            // }
            return true;
        }

    }

    return false;
}

bool posible(int y, int x)
{

    for (int i = 0; i < 4; i++)
    {

        int x1 = x + pi[i],
            y1 = y + pj[i];

        if (x1 >= 0 && x1 < m && y1 >= 0 && y < n && mat[y1][x1] == mat[y][x])
        {
            clean();
            memo[y][x] = 1;
            if (bfs(y, x, y1, x1))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (posible(i, j))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}