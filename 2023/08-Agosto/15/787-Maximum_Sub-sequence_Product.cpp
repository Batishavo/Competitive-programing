/*
    Author: Batishavo
    problem:787 Maximum Sub-sequence Product
    link:https://onlinejudge.org/external/7/787.pdf
*/

#include <bits/stdc++.h>

using namespace std;

long long maximum_Sub_sequence(vector<long long> nums)
{

    long long mayor = INT_MIN;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        //cout<<nums[i]<<" ";
        long long tmp = 1;
        for (int j = i; j < n; j++)
        {
            tmp *= nums[j];
            mayor = max(mayor, tmp);
        }
    }
    //cout<<endl;
    return mayor;
}

int main()
{
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    long long n;

    vector<long long> nums;

    while (cin >> n)
    {
        if (n == -999999)
        {
            cout << maximum_Sub_sequence(nums) << endl;
            nums.clear();
            continue;
        }
        nums.push_back(n);
    }

    return 0;
}