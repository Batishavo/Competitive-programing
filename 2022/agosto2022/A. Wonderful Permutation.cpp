#include<bits/stdc++.h>

using namespace std;

const int limit = 200;

int t,
    n,
    k,
    cont,
    aux;
int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&k);
        cont=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&aux);
            if(i<=k && aux>k){
                cont++;
            }

        }
        printf("--%d\n",cont);

    }

    return 0;
}
