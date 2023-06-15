#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int n;

long long num,
    sum,
    memo[limit];

pair<long long, long long> my_values[limit];

bool order(pair<long long, long long> a, pair<long long, long long> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int binary_search(int ini, long long max_price)
{
    int fin = n;
    while (ini < fin)
    {

        int mid = (ini + fin) / 2 + 1;

        if (my_values[mid].first >= max_price)
        {
            fin = mid - 1;
        }
        else
        {
            ini = mid;
        }
    }
    return ini;
}

long long sum_of_poor_child(int pos)
{

    int right = binary_search(pos, my_values[pos].first + num),
        left = pos;
    //printf("%d %d ",left,right);
    return memo[right] - memo[left - 1];
}

int main()
{

    scanf("%d %lld", &n, &num);

    for (int i = 1; i <= n; i++)
    {

        long long money,
            friendship;

        scanf("%lld %lld", &money, &friendship);

        my_values[i] = {money, friendship};
    }

    my_values[0] = {0, 0};

    sort(my_values, my_values + n + 1, order);

    for (int i = 1; i <= n; i++)
    {
        memo[i] = memo[i - 1] + my_values[i].second;
    }

    for (int i = 1; i <= n; i++)
    {
        long long aux = sum_of_poor_child(i);
        //printf("%lld\n",aux);
        sum = max(sum, aux);
    }

    // for(int i=0;i<=n;i++){
    //     cout<<my_values[i].first<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<=n;i++){
    //     cout<<my_values[i].second<<" ";
    // }
    // cout<<endl;

    printf("%lld\n", sum);

    return 0;
}