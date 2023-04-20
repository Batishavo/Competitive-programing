#include<bits/stdc++.h>

using namespace std;

int n,
    aux,
    bucket[5];

int main(){

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>aux;
        bucket[aux]++;
    }   
    for(int i=0;i<3;i++){
        for(int j=0;j<bucket[i];j++){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    

    return 0;
}