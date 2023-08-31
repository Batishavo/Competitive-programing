#include <bits/stdc++.h>

using namespace std;

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int m;
    int t;
    int pos;

    string name = "vika";

    bool flag;

    char mat[25][25];

    scanf("%d", &t);

    while (t--)
    {

        flag = false;
        pos = 0;

        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }

        for (int col = 0; col < m; col++)
        {
            for (int row = 0; row < n; row++)
            {
                if (mat[row][col] == name[pos])
                {
                    pos++;
                    break;
                }
            }
            if (pos == name.length())
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}