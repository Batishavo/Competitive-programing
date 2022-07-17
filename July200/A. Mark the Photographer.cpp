#include<bits/stdc++.h>

using namespace std;

const int limit = 10e3+10;

int arr[limit];

bool can(int n,int x){

    for(int i=0;i<n;i++){

        if(arr[i+n]-arr[i]<x){
            return false;
        }
    }
    return true;

}

int main(){

    int test;

    scanf("%d",&test);

    while (test--){

        int n,
            x;

        scanf("%d %d",&n,&x);

        for(int i=0;i<2*n;i++){

            scanf("%d",&arr[i]);
        }

        sort(arr,arr+(n*2));

        bool flag = can(n,x);

        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}
