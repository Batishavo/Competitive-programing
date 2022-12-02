#include<bits/stdc++.h>

using namespace std;

long long n;
int    t;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%lld",&n);
        //printf("--");
        if(n==1){
            printf("2\n");
        }
        else if(n%3==0){

            printf("%lld\n",n/3);

        }
        else{
            printf("%lld\n",(n/3)+1);
        }

    }



    return 0;
}
