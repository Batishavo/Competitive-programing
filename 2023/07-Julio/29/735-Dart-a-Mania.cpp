#include <bits/stdc++.h>

using namespace std;

int memo[70][70][70];
int used[70];

vector<int> get_points()
{
    vector<int> points;
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (used[i * j] == 0)
            {
                used[i * j] = 1;
                points.push_back(i * j);
            }
        }
    }
    points.push_back(0);
    points.push_back(50);
    return points;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int permutation;
    int combination;
    int used[5];

    vector<int> points = get_points();

    int tam = points.size();

    while (cin >> n)
    {

        if (n <= 0)
        {
            break;
        }

        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                for (int k = 0; k < tam; k++)
                {
                    memo[i][j][k] = 0;
                }
            }
        }

        combination = 0;
        permutation = 0;

        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                for (int k = 0; k < tam; k++)
                {

                    if (points[i] + points[j] + points[k] == n)
                    {
                        permutation++;

                        used[0] = i;
                        used[1] = j;
                        used[2] = k;

                        sort(used, used + 3);

                        if (memo[used[0]][used[1]][used[2]] == 0)
                        {
                            combination++;
                            memo[used[0]][used[1]][used[2]] = 1;
                        }
                    }
                }
            }
        }

        if (permutation == 0)
        {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        }
        else
        {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, combination);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, permutation);
        }

        cout << "**********************************************************************" << endl;
    }

    cout << "END OF OUTPUT"<<endl;

    return 0;
}