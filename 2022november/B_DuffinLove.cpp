#include <bits/stdc++.h>

using namespace std;

long long n;

vector<long long> nums;

stack<long long> tmp;

int main()
{

    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            nums.push_back(i);
            tmp.push(n / i);
        }
    }

    while (!tmp.empty())
    {
        nums.push_back(tmp.top());
        tmp.pop();
    }

    // for (int i = nums.size() - 1; i >= 0; i--){
    //     cout << nums[i] << " ";
    // }

    // cout<<endl;
    if (nums.size() == 2)
    {
        cout << n << endl;
    }
    else
    {
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            // cout << "**"<< nums[i] <<endl;

            bool flag = true;
            for (int j = sqrt(nums[i]); j >= 2; j--)
            {
                long long aux = pow(j, 2);
                if (nums[i] % aux == 0)
                {
                    // printf("++n: %lld aux: %lld mod: %lld\n",n,aux,n%aux);
                    flag = false;
                    break;
                }
                // printf("--n: %lld aux: %lld mod: %lld\n",n,aux,n%aux);
            }
            // cout<<endl;
            if (flag)
            {
                cout << nums[i] << endl;
                return 0;
            }
        }
    }

    return 0;
}