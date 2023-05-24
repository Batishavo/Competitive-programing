#include <bits/stdc++.h>

using namespace std;

int t,
    mini,
    maxi,
    mat[3][3];

int main()
{

    scanf("%d", &t);

    while (t--)
    {
        mini = INT_MAX;
        maxi = INT_MIN;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> mat[i][j];
                mini = min(mini, mat[i][j]);
                maxi = max(maxi, mat[i][j]);
            }
        }
        if (((mat[0][0] == mini || mat[0][0] == maxi)  &&
             (mat[1][1] == mini || mat[1][1] == maxi)) ||
            ((mat[0][1] == mini || mat[0][1] == maxi)  &&
             (mat[1][0] == mini || mat[1][0] == maxi)))
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