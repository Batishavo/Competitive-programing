#include<bits/stdc++.h>
using namespace std;
const int limit=1e5+10;
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
        int litle=arr[0];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                arr[j]-=arr[i];
            }
            if(arr[i+1]>litle && i+1<n){
                litle=arr[i+1];
            }
        }
        printf("%d\n",litle);
    }
    return 0;
}
