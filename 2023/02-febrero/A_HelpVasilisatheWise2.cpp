#include <bits/stdc++.h>

using namespace std;

int arr[5][5];

bool can(int i,int j,int k,int x)
{
    if(i==j || i==k || i==x ||
       j==k || j==x || 
       k==x){
        return false;
    }
    if (i + k != arr[2][1] ||
        j + x != arr[2][2] ||
        k + x != arr[1][2] ||
        i + j != arr[1][1] ||
        i + x != arr[3][1] ||
        j + k != arr[3][2])
    {
        return false;
    }

    return true;
}

int main()
{

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                for (int x = 1; x <= 9; x++)
                {
                    if (can(i, j, k, x))
                    {
                        printf("%d %d \n%d %d\n", i, j, k, x);
                        return 0;
                    }
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}