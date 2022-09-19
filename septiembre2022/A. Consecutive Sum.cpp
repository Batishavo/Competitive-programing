#include<bits/stdc++.h>

using namespace std;

int n,t,k,
    arr[110],
    arr2[110];

long long  calcula(int ini){
    long long cont=0;
    for(int i=ini;i<ini+k;i++){
        cont+=arr[i];
    }
    return cont;

}

int main(){

    scanf("%d ",&t);

    while(t--){

        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
            arr2[i]=arr[i];
        }

        long long cont=calcula(1);

        for(int i=k+1;i<=n;i++){

            long long aux = calcula(i-k+1),
                      tmp = aux;

            for(int j=i;j>i-k;j--){

                for(int x=i-k-1;x>=1;x--){

                    if(arr2[j]<arr2[x] && j%k==x%k){
                        tmp=tmp+arr2[x]-arr2[j];

                        int piv=arr2[j];
                        arr2[j]=arr[x];
                        arr2[x]=piv;

                    }

                }
                aux=max(aux,tmp);

            }

            for(int j=1;j<=i;j++){
                arr2[j]=arr[j];
            }

            cont=max(aux,cont);

        }


        printf("--%lld\n",cont);

    }


    return 0;

}
