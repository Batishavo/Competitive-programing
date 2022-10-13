#include<bits/stdc++.h>

using namespace std;

int t,a,b,c;

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>a>>b>>c;

        if(a+b==c || a+c==b || b+c==a){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    
    }
    

    return 0;
}