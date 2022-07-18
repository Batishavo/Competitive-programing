#include<bits/stdc++.h>

using namespace std;

const int limit=1e5+10;

int arr[limit],
    bucket[limit],
    used[limit];

int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        int n;

        scanf("%d",&n);

        for(int i=1;i<=n;i++){

            scanf("%d",&arr[i]);

            if(used[arr[i]]==0){

                used[arr[i]]=i;

                bucket[arr[i]]=1;

            }



        }
        /*printf("----\n");
        for(int i=1;i<=n;i++){

            printf("%d ",bucket[i]);

        }

         printf("\n");

        for(int i=1;i<=n;i++){

            printf("%d ",used[i]);

        }

        printf("\n");*/

        for(int i=1;i<=n;i++){

            if(used[arr[i]]!=i){

                int dif = i+1 - used[arr[i]];

                if(dif%2==0 || dif==1){

                    bucket[arr[i]]++;

                }

                used[arr[i]] = i;

            }


        }

        for(int i=1;i<=n;i++){

            printf("%d ",bucket[i]);

            bucket[i]=0;
            used[i]=0;

        }
        printf("\n");

    }

    return 0;
}
