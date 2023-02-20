#include<bits/stdc++.h>

using namespace std;

int n,k,arr[500];

int main(){

    cin>>n>>k;

    for(int i=0;i<n*2+1;i++){
        cin>>arr[i];
    }
    int pos=1;
    while(k>0){
        if(arr[pos]-arr[pos-1]>=2 && arr[pos]-arr[pos+1]>=2){
            k--;
            arr[pos]--;
        }
        pos+=2;
    }
    //printf("--%d/",n);
    for(int i=0;i<n*2+1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}