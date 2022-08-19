#include<bits/stdc++.h>

using namespace std;

vector<int>nums;

int n,t;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        for(int i=0;i<n;i++){
            int aux;
            scanf("%d",&aux);
            nums.push_back(aux);
        }
        sort(nums.begin(),nums.end());

        long long num=nums[n-1]+nums[n-2]-nums[0]-nums[1];

        printf("%lld\n",num);

        nums.clear();

    }

    return 0;
}
