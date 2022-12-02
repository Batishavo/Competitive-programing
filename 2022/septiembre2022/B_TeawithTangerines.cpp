#include<bits/stdc++.h>

using namespace std;

int t,n,arr[110];

long long cont;


int main(){

    scanf( "%d",&t);
    
    while(t--){
        cont=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);

        for(int i=1;i<n;i++){

            if(arr[i]>=arr[0]*2){
                int aux=arr[i]%((arr[0]*2)-1)==0?0:1;
                int cant=(arr[i]/((arr[0]*2)-1))+aux;
                cont+=cant-1;
            }

        }
        printf("%d\n",cont);
    }   

    return 0;
}