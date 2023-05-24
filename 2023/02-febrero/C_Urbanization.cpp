#include <bits/stdc++.h>

using namespace std;

const int limit = 10e6 + 10;

int n,
    n1,
    n2;

long long num1,
    num2,
    arr[limit];

double answer = 0;

int main()
{

    cin >> n >> n1 >> n2;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    reverse(arr, arr + n);
    int les = min(n1, n2),
        more = max(n1, n2);

    for (int i = 0; i < les; i++)
    {
        num1 += arr[i];
    }
    for (int i = les; i < n1 + n2; i++)
    {
        num2 += arr[i];
    }
    answer = ((long double)num1 / (long double)les) + ((long double)num2 / (long double)more);
    printf("%llf",answer);
    return 0;
}