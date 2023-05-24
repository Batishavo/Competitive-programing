#include<bits/stdc++.h>

using namespace std;

const int limit = 10e3+10;

int n,
    pos,
    arr[limit],
    result[limit];

int main(){

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    for(int i=0;i<n;i+=2){
        result[i]=arr[pos++];
    }
    for(int i=1;i<n;i+=2){
        result[i]=arr[pos++];
    }
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}