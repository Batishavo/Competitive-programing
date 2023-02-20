#include<bits/stdc++.h>

using namespace std;

const int limit = 10e5+10;

int n,
    k,
    aux,
    aux2,
    cont;

int main(){

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>aux>>aux2;
        cont+=aux2-aux+1;
    }
    if(cont%k==0){
        cout<<0<<endl;
    }
    else{
        int tmp=cont%k;
        cout<<k-tmp<<endl;
    }
    

    return 0;
}