#include <bits/stdc++.h>

using namespace std;

long long t,
    n,
    m,
    a,
    d,
    num,
    res,
    sum;

vector<long long> nums;

int main()
{

    scanf("%d", &t);

    while (t--)
    {
        nums.clear();
        res=sum=0;
        cin >> n >> m >> a >> d;
        num = m - n;
        nums.push_back(a);
        res+=num/a;
        bool flag2=1;
        for (int i = 1; i <= 4; i++)
        {
            long long tmp = a + (d * i);
            bool flag = 1;
            for (auto x : nums)
            {
                if (tmp % x == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                if(flag2){
                    flag2=0;
                    sum--;
                }
                sum--;
                nums.push_back(tmp);
                res+=num/tmp;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                long long tmp =nums[i]*nums[j]/__gcd(nums[i],nums[j]);
                sum+=num/tmp;
            }
        }
        // cout<<"--";
        // printf("num: %lld sum: %lld res: %lld\n",num,res,sum);
        cout << num - res + sum<<endl;
    }
    return 0;
}