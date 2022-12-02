#include<bits/stdc++.h>

using namespace std;

int t,n,m;

int main(){

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);

        if(n==1 && m==1){
            printf("0\n");
        }
        else{
            printf("%d\n",(min(m,n))+(n+m-2));
        }


    }

    return 0;
}
