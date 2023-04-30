#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int t,
    n,
    m,
    arr[limit];

map<int, int> used;

int main()
{
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {
        used.clear();
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        used[m] = 2;

        for (int i = 0; i < n; i++)
        {
            if (!used[arr[i]])
            {

                used[arr[i]] = 1;
                if (arr[i] < m && !used[m - arr[i]])
                {

                    used[m - arr[i]] = 2;
                }
                // cout<<arr[i]<<" "<<m-arr[i]<<endl;
            }
            // cout<<endl;
            if (used[arr[i]] == 1)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }

            if (arr[i] <= m && m - arr[i] == arr[i])
            {
                if (used[arr[i]] == 1)
                {
                    used[arr[i]] = 2;
                }
                else
                {
                    used[arr[i]] = 1;
                }
            }
        }
        printf("\n");
    }

    return 0;
}