#include <bits/stdc++.h>

using namespace std;

int kadane(int arr[], int n)
{

    int max_ending_here = 0;
    int max_so_far = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        max_ending_here = max(max_ending_here + arr[i], arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int max_sub_matrix_sum(int mat[][110], int n)
{

    int max_sum = INT_MIN;

    for (int left = 0; left < n; left++)
    {

        int temp[110] = {0};

        for (int right = left; right < n; right++)
        {
            for (int i = 0; i < n; i++)
            {
                temp[i] += mat[i][right];
            }
            int current_sum = kadane(temp, n);
            max_sum = max(max_sum, current_sum);
        }
    }

    return max_sum;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int mat[110][110];

    while (cin >> n)
    {
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cin >> mat[row][col];
            }
        }

        cout << max_sub_matrix_sum(mat, n) << endl;
    }
    return 0;
}