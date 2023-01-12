#include<bits/stdc++.h>

using namespace std;

long long n,x;

int main(){

    while(true){
        cin>>n;
        if(n==0){
            return 0;
        }
        x=sqrt(n);
        if(n==x*x){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }

    return 0;
}