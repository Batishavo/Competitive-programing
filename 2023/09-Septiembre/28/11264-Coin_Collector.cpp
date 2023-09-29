#include <bits/stdc++.h>

using namespace std;

long long arr[300];

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;
    int n;
    int answer;

    long long sum;

    cin >> t;

    while (t--)
    {
        answer = 1;
        sum = 0;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sum = arr[0];

        for (int i = 1; i < n - 1; i++)
        {

            if (sum + arr[i] < arr[i + 1])
            {
                sum += arr[i];
                answer++;
            }
        }
        if (n > 1)
        {
            answer++;
        }
        cout  << answer  << endl;
    }

    return 0;
}