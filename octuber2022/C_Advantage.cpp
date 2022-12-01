#include<bits/stdc++.h>

using namespace std;

const int limit =2*10e5+10;

int t,
    n,
    arr[limit],
    arr2[limit];

int main(){

    scanf( "%d",&t);
    
    while(t--){
        
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr2[i]=arr[i];
        }

        sort(arr2,arr2+n);
        //cout<<"-------"<<endl;
        for(int i=0;i<n;i++){
            if(arr[i]==arr2[n-1]){
                cout<<arr[i]-arr2[n-2]<<" ";
            }
            else{
                cout<<arr[i]-arr2[n-1]<<" ";
            }
        }        
        cout<<endl;
    
    }

    return 0;
}