#include <cstdio>
#include <cmath>

const int N = 1000010;

double y[N], mx[N];

int main()
{
    int p, a, b, c, d, n;
    while (scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n) == 6)
    {
        if (n == 1)
        {
            puts("0");
            continue;
        }
        for (int i = 1; i <= n; ++i)
        {
            y[i] = p * (sin(a * i + b) + cos(c * i + d) + 2);
            mx[i] = fmax(mx[i - 1], y[i]);
        }
        double ans = 0;
        for (int i = 2; i <= n; ++i)
            ans = fmax(ans, mx[i - 1] - y[i]);
        printf("%.10lf\n", ans);
    }
    return 0;
}