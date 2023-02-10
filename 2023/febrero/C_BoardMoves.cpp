#include<bits/stdc++.h>

using namespace std;

long long n,
    t;

long long acumulado;

int main(){

    scanf( "%lld",&t);
    
    while(t--){
        
        acumulado=0;
        
        long long tmp = 1,
            sum = 0,
            piv = 0;

        cin>>n;
        n*=n;
        while(n>0){
            //printf("%lld %lld\n",sum,piv);
            n-=tmp;
            acumulado+=sum*piv;
            tmp+=8;
            piv+=1;
            sum+=8;
        }
        //cout<<"--";
        cout<<acumulado<<endl;
    
    }

    return 0;
}