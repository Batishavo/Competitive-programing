#include <bits/stdc++.h>

using namespace std;

int n,
    k,
    actual_x,
    actual_y,
    x,
    y;

double answer = 0.0;

double dis()
{
    return sqrt(pow(actual_x - x, 2) + pow(actual_y - y, 2) * 1.0);
}

int main()
{

    cin >> n >> k >> x >> y;

    for (int i = 1; i < n; i++)
    {
        cin >> actual_x >> actual_y;
        answer += dis();
        x = actual_x;
        y = actual_y;
    }

    printf("%.9lf\n",(answer * (double)k)/(double)50);

    return 0;
}