#include<bits/stdc++.h>

using namespace std;

long long n,m;

int main(){

    cin>>n>>m;
    bool flag = false;
    for(long long i=n;i<=m;i++){
        for(long long j=i+1;j<=m;j++){
            for(long long k=j+1;k<=m;k++){
                if(__gcd(i,j)==1 && __gcd(j,k)==1 && __gcd(i,k)!=1){
                    printf("%lld %lld %lld\n",i,j,k);
                    return 0;
                }
            }
        }
    }
    printf(flag?"":"-1\n");
    return 0;
}