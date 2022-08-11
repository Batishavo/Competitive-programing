#include<bits/stdc++.h>

using namespace std;

const int limit = 10e5+10;

int n,
    m,
    t,
    cont,
    arr[limit],
    x[limit],
    y[limit],
    nodes[limit];

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&m);

        for(int i=1;i<=n;i++){

            nodes[i] = 0;
            scanf("%d",&arr[i]);

        }
        for(int i=0;i<m;i++){
            scanf("%d %d",&x[i],&y[i]);

            nodes[x[i]]++;
            nodes[y[i]]++;

        }

        cont=INT_MAX;

        if(m%2==0){
            cont=0;
        }
        else{

            for(int i=1;i<=n;i++){

                if(nodes[i]%2==1){
                    cont=min(cont,arr[i]);
                }

            }

            for(int i=0;i<m;i++){

                if(nodes[x[i]]%2==0 && nodes[y[i]]%2==0){

                    cont=min(cont,arr[x[i]]+arr[y[i]]);

                }

            }

        }

        printf("%d\n",cont);

    }

    return 0;

}
