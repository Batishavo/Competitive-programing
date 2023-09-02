#include <bits/stdc++.h>

using namespace std;

int mat[500][500];

int maximun_sum(int n)
{

    int answer = -1000000;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = i; k < i + n; k++)
            {
                for (int l = j; l < j + n; l++)
                {
                    int sum = mat[k][l];

                    if (i > 0)
                    {
                        sum -= mat[i - 1][l];
                    }
                    if (j > 0)
                    {
                        sum -= mat[k][j - 1];
                    }
                    if (i > 0 && j > 0)
                    {
                        sum += mat[i - 1][j - 1];
                    }
                    answer = max(answer, sum);
                }
            }
        }
    }

    return answer;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;
    int n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n*2; i++)
        {
            for (int j = 0; j < n*2; j++)
            {
                if (i < n && j < n)
                {
                    cin >> mat[i][j];
                    mat[i][j + n] = mat[i][j];
                    mat[i + n][j] = mat[i][j];
                    mat[i + n][j + n] = mat[i][j];
                }

                if (i > 0)
                {
                    mat[i][j] += mat[i - 1][j];
                }
                if (j > 0)
                {
                    mat[i][j] += mat[i][j - 1];
                }
                if (i > 0 && j > 0)
                {
                    mat[i][j] -= mat[i - 1][j - 1];
                }
            }
        }

        cout << maximun_sum(n) << endl;
    }

    return 0;
}