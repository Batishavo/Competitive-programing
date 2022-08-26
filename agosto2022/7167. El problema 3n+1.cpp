#include<bits/stdc++.h>

using namespace std;

long long n,maxi;
int cont = 0;

int main(){

    scanf("%lld",&n);
    maxi=n;
    while(n!=1){

        if(n%2==0){
            n/=2;
        }
        else{
            n*=3;
            n++;
        }
        maxi=max(maxi,n);
        cont++;
    }

    printf("%d %lld\n",cont,maxi);

    return 0;
}
