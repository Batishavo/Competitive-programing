#include<bits/stdc++.h>

using namespace std;

int t,n,arr[20];

int main(){

    scanf( "%d",&t);
    
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        //cout<<"--";
        if(arr[0]==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}