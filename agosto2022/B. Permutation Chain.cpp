#include<bits/stdc++.h>

using namespace std;

int n,
    t,
    arr[110];

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            arr[i]=i;
        }

        printf("%d\n",n);

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){

                printf("%d ",arr[j]);
            }
            printf("\n");

            int aux  = arr[i+1];
            arr[i+1] = arr[i];
            arr[i]   = aux;

        }

    }

    return 0;
}
