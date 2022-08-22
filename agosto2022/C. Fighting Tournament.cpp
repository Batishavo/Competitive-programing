#include<bits/stdc++.h>

using namespace std;

const int limit=10e5+10;

int t,n,q,k,ai,
    cont,
    mayor,
    arr[limit],
    pos[limit],
    sum[limit];

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&q);

        cont=0;
        mayor=0;

        for(int i=1;i<=n;i++){
            sum[i]=0;
        }
        //printf("\n");*/
        for(int i=1;i<=n;i++){

            scanf("%d",&arr[i]);
            pos[arr[i]]=i;

            if(arr[i]>mayor){
                mayor=arr[i];
                cont=1;
            }
            if(i>1){
                sum[mayor]=cont++;
            }

        }

        /*for(int i=1;i<=n;i++){
            printf("%d ",pos[i]);
        }
        printf("\n");
        for(int i=1;i<=n;i++){
            printf("%d ",sum[i]);
        }
        printf("\n");*/

        //////////
        for(int i=0;i<q;i++){

            scanf("%d %d",&ai,&k);
             //printf("-----\n");

            if(ai-1>k || pos[arr[ai]]>pos[n] || sum[arr[ai]]==0){
                //printf("a\n");
                printf("0\n");
            }
            else if(ai==pos[n]){
                //printf("b\n");

                if(ai==1 || ai==2){
                    printf("%d\n",k);
                }
                else{
                    printf("%d\n",k-(pos[n]-2));
                }

            }
            else{
                //printf("c\n");

                if(k>=(pos[arr[ai]]+sum[arr[ai]]) ){
                   printf("%d\n",sum[arr[ai]]);
                }
                else{

                    int tmp=2;

                    if(ai==1 || ai==2){
                        tmp=1;
                    }
                    printf("%d\n",min(sum[arr[ai]],k-pos[arr[ai]]+tmp));
                }
            }


        }

    }

    return 0;
}
