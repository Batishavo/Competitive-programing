#include<bits/stdc++.h>

using namespace std;

int t,n,m,ln,lm,l;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d %d %d %d",&n,&m,&ln,&lm,&l);



        if((ln+l>=n && lm+l>=m)||
           (ln-l<=1 && lm-l<=1)||
           (ln+l>=n && ln-l<=1)||
           (lm-l<=1 && lm+l>=m)
           ){

            printf("%d\n",-1);
        }
        else{
            printf("%d\n",max(n+m-2,2));
        }



    }

    return 0;
}
