#include<bits/stdc++.h>

using namespace std;

const int limit = 20e5+10;

int n,
    t,
    cont,
    arr[limit],
    bucket[limit];

long long sum;

int main(){

    scanf("%d",&t);

    while(t--){

        cont = 0;
        sum  = 0;

        scanf("%d",&n);

        for(int i=1;i<=n;i++){

            scanf("%d",&arr[i]);

            if(arr[i]<i){
                cont++;
            }
            bucket[i]=cont;

        }

        for(int i=n;i>=1;i--){

            if(arr[i]< i && arr[i]-1>0){

                sum+=bucket[arr[i]-1];

            }

        }
        printf("%lld\n",sum);

    }

    return 0;
}
