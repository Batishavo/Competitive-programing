#include<bits/stdc++.h>

using namespace std;

int n,
    m,
    wire,
    pos,
    arr[105];

int main(){

    cin>>n;

    for(int i=1; i<=n; i ++){
        cin>>arr[i];
    }

    cin>>m;

    for(int i=1; i<=m; i++){
        cin>>wire>>pos;
        arr[wire-1]+=pos-1;
        arr[wire+1]+=arr[wire]-pos;
        arr[wire]=0;
    }

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}