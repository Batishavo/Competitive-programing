#include<bits/stdc++.h>

using namespace std;

int t,n;
long long arr[300];

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        bool flag = true;

        cin>>n;

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                flag= false;
                break;
            }
        }

        printf((flag)?"YES\n":"NO\n");
    }

    return 0;
}