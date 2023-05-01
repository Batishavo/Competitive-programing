#include<bits/stdc++.h>

using namespace std;

const int limit = 110;

int n,
    arr[limit];

void buble_cero(){
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(arr[j]!=0 && arr[j-1]==0){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

int main(){

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    buble_cero();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}