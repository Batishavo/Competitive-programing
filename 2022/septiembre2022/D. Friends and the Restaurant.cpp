#include<bits/stdc++.h>

using namespace std;

const int limit = (10e5)+10;

int t,
    n,
    cont,
    mat[limit][5],
    arr[limit];

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d",&mat[i][0]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&mat[i][1]);
        }
        for(int i=0;i<n;i++){
            arr[i]=mat[i][1]-mat[i][0];
        }
        sort(arr,arr+n);
        reverse(arr,arr+n);

        /*for(int i=0;i<n;i++){
            printf("*%d ",arr[i]);
        }
        printf("\n");*/
        int pi=0,pj=n-1;
        cont=0;
        while(pi<pj){
            if(arr[pi]+arr[pj]>=0){
                cont++;
                pi++;
                pj--;
            }
            else{
                pj--;
            }
        }
        printf("--%d\n",cont);

    }

    return 0;
}
