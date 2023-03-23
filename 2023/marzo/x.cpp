#include<iostream>
#include <algorithm>
#include <cassert>
#include <string>
#include <sstream>
#include <set>
#include <bitset>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <list>
#include <complex>
#include <functional>
    using namespace std;

#define me(s) memset(s, 0, sizeof(s))
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> P;

const int N = 1000000 + 10;

double y[N];
double mx[N];
int n;
int p, a, b, c, d;

int main()
{
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    while (~scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n))
    {
        if (n == 1)
        {
            puts("0");
            continue;
        }
        for (int i = 1; i <= n; i++)
            y[i] = p * (sin(a * i + b) + cos(c * i + d) + 2);
        mx[1] = y[1];
        for (int i = 2; i <= n; i++)
            mx[i] = max(y[i], mx[i - 1]);
        double ans = 0.0;
        for (int i = 2; i <= n; i++)
            ans = max(ans, mx[i - 1] - y[i]);
        printf("%.10lf\n", ans);
    }
}