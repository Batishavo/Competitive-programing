#include<bits/stdc++.h>

using namespace std;

int t,arr[5];

int main(){

    scanf( "%d",&t);
    
    while(t--){
        
        for(int i=0;i<3;i++){
            cin>>arr[i];
        }
        sort(arr,arr+3);
        //cout<<"--";
        cout<<arr[1]<<endl;
    
    }

    return 0;
}