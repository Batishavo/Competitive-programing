#include <bits/stdc++.h>

using namespace std;

int mat[500][500];

void ful_mat(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < n * 2; j++)
        {
            mat[i][j] = mat[i][j - n];
        }
    }
    for (int i = n; i < 2 * n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = mat[i - n][j];
        }
    }

    for (int i = n; i < 2 * n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            mat[i][j] = mat[i - n][j - n];
        }
    }
}

int kadane(int arr[], int n)
{
    int maxEndingHere = 0;
    int maxSoFar = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxEndingHere = max(maxEndingHere + arr[i], arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int maxSubmatSum(int rows, int cols,int n)
{
    int maxSum = INT_MIN;

    for (int left = 0; left < cols; left++)
    {
        int temp[100] = {0};

        for (int right = left; right < cols; right++)
        {
            for (int i = 0; i < rows; i++)
            {
                temp[i] += mat[i][right];
            }

            int currentSum = kadane(temp, rows);
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int t;
    int n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        ful_mat(n);
        // for(int i=0;i<n*2;i++){
        //     for(int j=0;j<n*2;j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout << maxSubmatSum(n*2,n*2,n) << endl;
    }

    return 0;
}