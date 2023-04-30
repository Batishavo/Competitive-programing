#include<bits/stdc++.h>

using namespace std;

int t;

int a,b;

int main(){

    scanf( "%d",&t);
    
    while(t--){
        int res=INT_MAX;
        cin>>a>>b;
        
        int c=min(a,b),
            d=max(a,b);

        if(c*2>d){
            res=c*2;
        }
        else{
            res=d;
        }


        //cout<<"--";
        cout<<res*res<<endl;
    
    }

    return 0;
}