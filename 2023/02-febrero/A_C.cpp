#include<bits/stdc++.h>

using namespace std;

int t,a,b,n;

int dp(int menor,int mayor){

    if(menor>n || mayor>n){
        return 0;
    }
    return dp(mayor,menor+mayor)+1;


}

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>a>>b>>n;
        cout<<dp(min(a,b),max(a,b))<<endl;
    
    }


    return 0;
}