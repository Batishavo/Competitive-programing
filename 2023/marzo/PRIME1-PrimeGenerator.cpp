#include <bits/stdc++.h>

using namespace std;

const int limit = sqrt(1000000000);

long long n,
    m,
    last;

int t;

bool memo[limit + 10];

vector<int> primes;

void criba()
{
    memo[0] = 1;
    memo[1] = 1;
    for (int i = 2; i <= limit; i++)
    {
        if (memo[i] == 0)
        {
            // cout<<i<<",";
            primes.push_back(i);
            for (int j = i + i; j <= limit; j += i)
            {
                memo[j] = 1;
            }
        }
    }
}

int main()
{
    criba();
    // cout<<primes.size();
    last = primes[primes.size() - 1];
    scanf("%d", &t);

    while (t--)
    {

        cin >> n >> m;
        for (long long i = n; i <= m; i++)
        {
            bool flag = 0;
            if (i > last)
            {
                for (int j = 0; j < primes.size(); j++)
                {
                    if (i % primes[j] == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << i << endl;
                }
            }
            else
            {
                if (memo[i] == 0)
                {
                    cout << i << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}