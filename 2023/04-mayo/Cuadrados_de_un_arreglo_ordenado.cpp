#include<bits/stdc++.h>

using namespace std;

const int limit = 110;

int n,
    arr[limit];

int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i] *=arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}