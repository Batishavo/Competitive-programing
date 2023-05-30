#include <bits/stdc++.h>

using namespace std;

const int limit = 30e3;

int n;

long long values[limit],
    cost[limit];

long long sum = INT_MAX;

int flag = 0;

int main()
{

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &values[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &cost[i]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        long long sum_l = INT_MAX;

        if (flag < 2)
        {
            flag = 0;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            if (values[j] < values[i])
            {
                sum_l = min(sum_l, cost[j]);
                flag++;
            }
        }
        long long sum_r = INT_MAX;

        for (int j = i + 1; j < n; j++)
        {
            if (values[j] > values[i])
            {
                sum_r = min(sum_r, cost[j]);
                flag++;
            }
        }

        sum = min(sum, sum_l + sum_r + cost[i]);
    }

    if (flag < 2)
    {
        printf("-1\n");
    }
    else
    {
        printf("%lld\n", sum);
    }

    return 0;
}