#include<bits/stdc++.h>

using namespace std;

const int limit =10e5+10;

int t,
    n,
    cont,
    arr[limit],
    bucket[limit];

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            scanf("%d",&arr[i]);

            if(bucket[arr[i]]==0){
                cont++;
            }
            bucket[arr[i]]++;

        }

        bucket[arr[n-1]]--;
        if(bucket[arr[n-1]]==0){
            cont--;
        }
        for(int i=n-2;i>=0;i--){

            if(arr[i]==arr[i+1]){

                bucket[arr[i]]--;

                if(bucket[arr[i]]==0){
                    cont--;
                }

                continue;

            }
            else if(arr[i]!=arr[i+1]){

                if(bucket[arr[i+1]]!=0 || arr[i]>arr[i+1]){

                    break;
                }
                bucket[arr[i]]--;
                if(bucket[arr[i]]==0){
                    cont--;
                }
            }

        }
        printf("%d\n",cont);
        cont=0;
        for(int i=0;i<n;i++){
            bucket[arr[i]]=0;
        }

    }

    return 0;
}
