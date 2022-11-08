#include <bits/stdc++.h>

using namespace std;

int menor = INT_MAX, x, y;

map<pair<long long, long long>, bool> memo;

bool flag = false;

void cal(int a, int b, int cont)
{
    // printf("%d %d\n",a,b);
    if (a == b)
    {
        menor = min(menor, cont);
        flag = true;
        return;
    }
    else if (a > b)
    {
        // cout<<"X"<<endl;
        if (a % 2 == 0 && !memo[{a / 2, b}])
        {
            memo[{a / 2, b}] = 1;
            cal(a / 2, b, cont + 1);
        }
        if (a % 3 == 0 && !memo[{a / 3, b}])
        {
            memo[{a / 3, b}] = 1;
            cal(a / 3, b, cont + 1);
        }
        if (a % 5 == 0 && !memo[{a / 5, b}])
        {
            memo[{a / 5, b}] = 1;
            cal(a / 5, b, cont + 1);
        }
    }
    else
    {
        // cout<<"Y"<<endl;
        if (b % 2 == 0 && !memo[{a, b / 2}])
        {
            memo[{a, b / 2}] = 1;
            cal(a, b / 2, cont + 1);
        }
        if (b % 3 == 0 && !memo[{a, b / 3}])
        {
            memo[{a, b / 3}] = 1;
            cal(a, b / 3, cont + 1);
        }
        if (b % 5 == 0 && !memo[{a, b / 5}])
        {
            memo[{a, b / 5}] = 1;
            cal(a, b / 5, cont + 1);
        }
    }
}

int main()
{

    cin >> x >> y;

    cal(x, y, 0);
    if (flag)
    {
        cout << menor << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}