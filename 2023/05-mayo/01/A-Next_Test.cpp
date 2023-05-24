#include<bits/stdc++.h>

using namespace std;

const int limit = 10e3 +10;

int n,
    arr[limit];


int main(){

    cin>>n;

    for(int i=0; i<n; i++){
        int aux;
        cin>>aux;
        arr[aux]=1;
    }

    for(int i=1; i<limit; i++){
        if(arr[i]==0){
            cout<<i<<endl;
            break;
        }
    }
    

    return 0;
}