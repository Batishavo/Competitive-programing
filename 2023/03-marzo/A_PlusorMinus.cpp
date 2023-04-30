#include<bits/stdc++.h>

using namespace std;

int t,
    a,
    b,
    c;

int main(){

    scanf( "%d",&t);
    
    while(t--){
        
        cin>>a>>b>>c;

        if(a+b==c){
            cout<<"+"<<endl;
        }
        else{
            cout<<"-"<<endl;
        }
    
    }

    return 0;
}