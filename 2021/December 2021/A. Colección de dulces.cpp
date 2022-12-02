#include<bits/stdc++.h>
using namespace std;
const int limit=1e7;
int arr[limit];
long long maxSubArraySum(int n)
{
    long long max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
        printf("%lld %lld %d\n",max_so_far,max_ending_here,i);
    }
    printf("***%lld\n",max_so_far);
    return max_so_far;
}
int main(){
    int test;
    scanf("%d",&test);
    for(int k=1;k<=test;k++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        long long maxSub=maxSubArraySum(n);
        printf("Case #%d: %lld\n",k,maxSub);
    }
    return 0;
}
