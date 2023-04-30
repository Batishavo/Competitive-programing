#include<bits/stdc++.h>

using namespace std;

const int limit = 20e3+10;

int n,
    vasya,
    broter,
    arr[limit];

int main(){

    cin>>n>>vasya>>broter;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    
    cout<<arr[broter]-arr[broter-1]<<endl;

    return 0;
}