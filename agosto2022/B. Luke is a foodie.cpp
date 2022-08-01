#include<bits/stdc++.h>

using namespace std;

const int limit = (2*10e5)+10;

long long arr[limit],
          my_min,
          my_max,
          comp;

int test,
    n    = 0,
    x    = 0,
    cont = 0;

int main(){

    scanf("%d",&test);

    while(test--){

         scanf("%d %d",&n,&x);

         for(int i=0;i<n;i++){

            scanf("%lld",&arr[i]);

         }

         my_min=arr[0];
         my_max=arr[0];
         comp=arr[0]+x;

         for(int i=1;i<n;i++){


           if(arr[i]>my_max){

                comp=(arr[i]-x>0?arr[i]-x:1);

                if(abs(comp-my_min)>x){

                    cont++;
                    my_min=arr[i];
                    my_max=arr[i];
                }
                else{
                    my_max=arr[i];
                }


           }
           else if(arr[i]<my_min){

                comp=arr[i]+x;

                if(abs(comp-my_max)>x){

                    cont++;
                    my_min=arr[i];
                    my_max=arr[i];
                }
                else{
                    my_min=arr[i];
                }

           }


         }

        printf("%d\n",cont);

        cont=0;

    }

    return 0;
}
