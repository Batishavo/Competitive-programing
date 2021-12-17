#include<bits/stdc++.h>
using namespace std;
const int limit=1e6+10;
int arr[limit];
int main(){
    int query;
    scanf("%d",&query);
    while(query--){
        int n;
        scanf("%d",&n);
        for(int i=0 ;i<n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        int litle=arr[0],total=arr[0];
        for(int i=1;i<n;i++){
            int aux=arr[i];
            arr[i]-=total;
            total+=arr[i];
            //printf("%d ",arr[i]);
            if(arr[i]>litle){
                litle=arr[i];
            }
        }
        printf("%d\n",litle);
    }
    return 0;
}
