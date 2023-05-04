#include <bits/stdc++.h>
using namespace std;

const int limit = (50 * 50) + 10;

int t,
    n,
    pares[limit][4],
    mat[60][60],
    memo[limit];

void llenarPares()
{
    int pos = 0,
        num1 = n * n,
        num2 = 0;
    for (int i = n * n - 1; i >= 1; i--)
    {
        if (pos == 2)
        {
            num1--;
            pos = 0;
        }
        else
        {
            num2++;
        }
        pares[i][0] = num1;
        pares[i][1] = num2;
        pos++;
    }
    /*for(int i=n*n-1;i>=1;i--){

        printf("%d %d %d\n",i,pares[i][0],pares[i][1]);

    }
    cout<<endl;*/
}

void llenarMat()
{
    // int cont=1;
    int p1 = n * n - 1;
    bool p2 = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = pares[p1][p2];
                p1--;
                p2 = !p2;
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                mat[i][j] = pares[p1][p2];
                p1--;
                p2 = !p2;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout<<"X";
            memo[mat[i][j]] = 1;
        }
        // cout<<endl;
    }
    int aux = 0;
    for (int i = 1; i <= n * n - 1; i++)
    {
        if (memo[i] == 0)
        {
            aux = i;
            break;
        }
    }
    // cout<<aux<<endl;
    for (int i = 0; i < n; i++)
    {
        // if(aux!=0)break;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                memo[aux] = 1;
                mat[i][j] = aux;
                break;
            }
        }
    }
    /////////////////////////
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            memo[mat[i][j]] = 0;
            mat[i][j] = 0;
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {

        cin >> n;
        llenarPares();
        llenarMat();
    }

    return 0;
}