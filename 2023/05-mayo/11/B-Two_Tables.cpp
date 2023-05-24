#include <bits/stdc++.h>

using namespace std;

int t,
    W,
    H,
    w,
    h,
    anwer,
    x[5],
    y[5];

int top()
{
    if (abs(y[2] - y[1]) + h > H)
        return -1;
    if (y[2] + h - H <= 0)
    {
        return 0;
    }
    return y[2] + h - H;
}

int bottom()
{
    if (abs(y[2] - y[1]) + h > H)
        return -1;
    int tam = y[1] - 1;
    if (h <= tam)
    {
        return 0;
    }
    return abs(tam - h);
}

int left()
{
    if (abs(x[2] - x[1]) + w > W)
        return -1;
    int tam = x[1] - 1;
    if (w <= tam)
    {
        return 0;
    }
    return abs(tam - w);
}

int right()
{
    if (abs(x[2] - x[1]) + w > W)
        return -1;
    if (x[2] + w - W <= 0)
    {
        return 0;
    }
    return x[2] + w - W;
}

void calcula()
{
    int aux[10];
    anwer = INT_MAX;

    aux[0] = top();
    aux[1] = bottom();
    aux[2] = left();
    aux[3] = right();

    for (int i = 0; i < 4; i++)
    {
        if (aux[i] != -1)
        {
            anwer = min(anwer, aux[i]);
        }
    }
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {

        scanf("%d %d", &W, &H);

        scanf("%d %d %d %d", &x[1], &y[1], &x[2], &y[2]);

        scanf("%d %d", &w, &h);

        x[1]++;
        x[2]++;
        y[1]++;
        y[2]++;

        if (
            (abs(x[2] - x[1]) + w <= W && abs(y[2] - y[1]) <= H && h <= H) ||
            (abs(y[2] - y[1]) + h <= H && abs(x[2] - x[1]) <= W && w <= W))
        {
            calcula();
            float tmp = float(anwer);
            printf("%.6lf\n", tmp);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}