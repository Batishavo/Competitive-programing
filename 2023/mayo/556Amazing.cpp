#include <bits/stdc++.h>

using namespace std;

const int limit = 1000;

int n,
    m,
    ans[10],
    memo[limit][limit],
    mov_j[4] = {1, 0,-1, 0},
    mov_i[4] = {0,-1, 0, 1};

string mat[limit];

void myprint()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '1')
            {
                cout << 'X';
            }
            else
            {
                cout << memo[i][j];
            }
        }
        cout << endl;
    }
    cout<<"------------"<<endl;
}

void recorido()
{
    int x = 0,
        y = n - 1,
        pos = 0;
    memo[y][x]++;
    int num=0;
    while (true)
    {
        num++;
        if(num>50){
            break;
        }
        int i = y + mov_i[pos],
            j = x + mov_j[pos];
        cout<<i<<" "<<j<<" "<<pos<<endl;
        if (j >= 0 && j < m && i >= 0 && i < n && mat[i][j] == '0')
        {
            if (i == n - 1 && j == 0)
            {
                break;
            }
            memo[i][j]++;
            x = j;
            y = i;
            myprint();
        }
        else
        {
            pos++;
            pos %= 4;
        }
    }
}
void contar()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '0')
            {
                ans[memo[i][j]]++;
            }
        }
    }
}

void clean()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            memo[i][j] = 0;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        ans[i] = 0;
    }
}

int main()
{
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    while (cin >> n >> m)
    {
        if (n == 0 & m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> mat[i];
        }
        recorido();
        contar();
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
        myprint();
        clean();
    }

    return 0;
}