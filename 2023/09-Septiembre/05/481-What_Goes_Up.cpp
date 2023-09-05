#include <bits/stdc++.h>

using namespace std;

void longest_sub(vector<int> &nums)
{

    int n = nums.size();

    vector<pair<int, int>> dp;

    for (int i = 0; i < n; i++)
    {
        dp.push_back({1, i});
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[i].first <= dp[j].first + 1)
                {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = j;
                }
            }
        }
    }

    int pos = 0;

    for (int i = 1; i < n; i++)
    {
        if (dp[i].first >= dp[pos].first)
        {
            pos = i;
        }
    }

    int tam = dp[pos].first;

    printf("%d\n-\n", tam);
    // for(int i=0;i<n;i++){
    //     cout<<dp[i].second<<" ";
    // }
    // cout<<endl;
    vector<int>res;
    for (int i=0;i<tam;i++)
    {
        res.push_back(nums[pos]);
        pos = dp[pos].second;
    }
    for(int i=tam-1;i>=0;i--){
        cout<<res[i]<<"\n";
    }
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    vector<int> nums;
    int num;

    while (cin >> num)
    {
        nums.push_back(num);
    }

    longest_sub(nums);

    return 0;
}