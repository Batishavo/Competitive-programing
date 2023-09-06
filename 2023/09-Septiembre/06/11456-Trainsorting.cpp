#include <bits/stdc++.h>

using namespace std;

int lon_sub(vector<int> &arr)
{

    int n = arr.size();

    vector<int> dp(n, 1);
    vector<int> dp_r(n, 0);

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                dp_r[i] = max(dp_r[i], dp_r[j] + 1);
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        answer = max(answer, dp[i] + dp_r[i]);
    }

    return answer;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;
    int num;
    int n;
    vector<int> arr;
    cin >> t;
    while (t--)
    {
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>num;
            arr.push_back(num);
        }
        cout << lon_sub(arr)<<endl;
        arr.clear();
    }
    return 0;
}