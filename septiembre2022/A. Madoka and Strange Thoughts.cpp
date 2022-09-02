#include<bits/stdc++.h>

using namespace std;

int t,n;

int main(){

    scanf("%d",&t);

    while(t--){


        scanf("%d",&n);

        long long cont=n;
        cont+=(n/3)*4;
        cont+=((n/2)-(n/3))*2;

        printf("%lld\n",cont);

    }

}
