#include<bits/stdc++.h>

using namespace std;

int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        int n,m,pi=0,pj=0,maxValue=INT_MIN;

        scanf("%d %d",&n,&m);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                int aux;
                scanf("%d",&aux);

                if(aux>maxValue){
                    maxValue = aux;
                    pi=i;
                    pj=j;
                }


            }
        }
        printf("--%d %d\n",pi,pj);
        printf("--%d %d\n",max(pi,n-pi+1),max(pj,m-pj+1));
         printf("%d\n",max(pi,n-pi+1)*max(pj,m-pj+1));

    }


    return 0;
}
