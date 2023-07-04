#include <bits/stdc++.h>

using namespace std;

const int limit = 10e6 + 10;

int memo[limit];
set<int, greater<int>> nums;

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n, m;
    long long sum = 0;

    while (scanf("%d", &n))
    {

        if (n == 0)
        {
            break;
        }

        while (n--)
        {
            scanf("%d", &m);
            for (int i = 0; i < m; i++)
            {
                int aux;
                scanf("%d", &aux);
                nums.insert(aux);
                memo[aux]++;
            }
            if (nums.size() > 1)
            {
                auto mayor = nums.begin();
                auto menor = nums.rbegin();
                // cout << "# ";
                // for (auto &str : nums)
                // {
                //     cout << str << " ";
                // }
                // cout << endl;
                // printf("%d %d\n", *mayor, *menor);
                sum += *mayor - *menor;
                memo[*mayor]--;
                memo[*menor]--;
                if (memo[*mayor] == 0)
                {
                    nums.erase(mayor);
                }
                if (memo[*menor] == 0)
                {
                    nums.erase(--nums.end());
                }
            }
            else{
                auto pos = nums.begin();
                memo[*pos]-=2;
                if(memo[*pos] == 0){
                    nums.erase(pos);
                }
            }
        }

        printf("%lld\n", sum);

        for (auto &str : nums)
        {
            memo[str] = 0;
        }
        nums.clear();
        sum = 0;
    }

    return 0;
}