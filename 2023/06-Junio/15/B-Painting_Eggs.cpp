#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> pair_ll;

const int limit = 10e6 + 10,
          price = 1000,
          price_limit = 500;

int n;

ll sum_A,
    sum_B;

pair_ll nums[limit];

string cad_a,
    cad_b;

bool process(int sum, char ini, char fin, string &cad)
{
    for (int i = 0; i < n; i++)
    {
        if (sum <= price_limit)
        {
            cad += fin;
        }
        else
        {
            cad += ini;
            sum -= price;
        }
    }
    return sum <= price_limit;
}

bool can_a()
{
    return process(sum_A, 'G', 'A', cad_a);
}

bool can_b()
{
    return process(sum_B, 'A', 'G', cad_b);
}

int main()
{

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &nums[i].first, &nums[i].second);
        sum_A += nums[i].first;
        sum_B += nums[i].second;
    }

    if (can_a())
    {
        cout << cad_a << endl;
    }
    else if (can_b())
    {
        cout << cad_b << endl;
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}