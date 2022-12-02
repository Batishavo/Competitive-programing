#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        long long arr[4];
        for(int i=0;i<3;i++){
            scanf("%lld",&arr[i]);

        }
        sort(arr,arr+3);

        if(arr[0]+arr[1]<arr[2]){

            printf("%lld\n",arr[2]-arr[1]-arr[0]+1);
        }
        else{
            printf("%lld\n",arr[2]+1);
        }

    }

    return 0;

}
