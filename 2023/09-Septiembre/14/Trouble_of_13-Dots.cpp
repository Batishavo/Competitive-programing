#include <bits/stdc++.h>

using namespace std;

int knapsack(
    vector<int> &weights, vector<int> &values, int n, int capacity)
{

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= capacity; ++w)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int m;
    int n;

    int weight;
    int value;

    vector<int> weights;
    vector<int> values;

    while (cin >> m >> n)
    {

        weights.clear();
        values.clear();

        for (int i = 0; i < n; i++)
        {
            cin >> weight >> value;

            weights.push_back(weight);
            values.push_back(value);
        }
        int num1 = knapsack(weights, values, n, m);
        int num2 = knapsack(weights, values, n, m + 200);
        cout<<num1<<" "<<num2<<endl;
        if (num2 >= 2000)
        {
            cout << num2 << endl;
        }
        else
        {
            cout << num1 << endl;
        }
    }

    return 0;
}