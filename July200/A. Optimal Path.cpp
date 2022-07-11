#include<bits/stdc++.h>

using namespace std;

int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        long long n,m,result;

        scanf("%lld %lld",&n,&m);


        result = (m *(m+1)/2);

        for(int i=2;i<=n;i++){
            result+=m*i;
        }


        printf("--%lld\n",result);


    }

    return 0;
}
