#include<bits/stdc++.h>

using namespace std;

const int limit = 2*10e5+10;

int n,
    piv,
    arr[limit];

long long suma;

int main(){

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    suma+=arr[n-1];
    piv=max(arr[n-1]-1,0);
    //cout<<suma<<" "<<piv<<endl;
    for(int i=n-2;i>=0;i--){
        if(arr[i]==0){
            piv=0;
            continue;
        }
        else if(arr[i]<=piv){
            suma+=arr[i];
            piv=max(arr[i]-1,0);
        }
        else{
            suma+=piv;
            piv=max(piv-1,0);
        }
        //cout<<suma<<" "<<piv<<endl;
    }

    cout<<suma<<endl;

    return 0;
}