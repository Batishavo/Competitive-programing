#include <bits/stdc++.h>

using namespace std;

int n,
    t1,
    t2,
    k;

pair<int, double> values[1005];

double calculate(int num1, int num2)
{
    double f_t1 = (double)t1,
          f_t2 = (double)t2,
          t_num1 = (double)num1,
          t_num2 = (double)num2,
          t_k = (double)k,
          p = (t_k/100.00);

    return (t_num1*f_t1)-((t_num1*f_t1)*p)+f_t2*t_num2;
}

bool compare(pair<int, double> a, pair<int, double> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{

    cin >> n >> t1 >> t2 >> k;

    for (int i = 0; i < n; i++)
    {

        int num1,
            num2;

        cin >> num1 >> num2;

        double con1 = calculate(num1, num2),
              con2 = calculate(num2, num1);

        values[i] = {i + 1, max(con1, con2)};
    }

    sort(values, values + n, compare);

    for (int i = 0; i < n; i++)
    {
        printf("%d %.2lf\n", values[i].first, values[i].second);
    }

    return 0;
}