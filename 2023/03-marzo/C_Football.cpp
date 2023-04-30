#include <bits/stdc++.h>

using namespace std;

const int limit = 1005;

int n,
    k,
    arr[limit],
    total;

int main()
{
    scanf("%d %d", &n, &k);

    if (n <= 2)
    {
        printf("-1\n");
    }
    else
    {
        int num = ((n - 1) * (n)) / 2,
            mol = num % k,
            cant = num / k;
        if (k <= num / n)
        {
            printf("%d\n", n * k);
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (arr[i] < k)
                    {
                        arr[i]++;
                        printf("%d %d\n", i, j);
                        if (arr[i] == k)
                            total++;
                    }
                    else if (arr[j] < k)
                    {
                        printf("%d %d\n", j, i);
                        arr[j]++;
                        if (arr[j] == k)
                            total++;
                    }

                    if (total == n)
                    {
                        break;
                    }
                }
                if (total == n)
                {
                    break;
                }
            }
        }
        else
        {
            printf("-1");
        }
    }

    return 0;
}