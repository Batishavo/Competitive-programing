#include<bits/stdc++.h>

using namespace std;


int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        long long n;

        scanf("%lld",&n);

        if(n%2==0){
            printf("%lld 0 0\n",n/2);
        }
        else{
            printf("-1\n");
        }


    }

    return 0;
}
