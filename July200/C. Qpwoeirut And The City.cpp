#include<bits/stdc++.h>

using namespace std;

const int limit = (2*10e5)+10;

int test,
    n,
    arr[limit];

long long solution,
          menor,
          sumatoria[limit];

void calculos(int ini){

    long long anterior = 0;

    for(int i=ini;i<n-1;i+=2){

        long long maximo = max(arr[i-1],arr[i+1]);

        long long total=0;

        if(maximo>=arr[i]){

            total= maximo - arr[i]+1;
        }

        sumatoria[i] = anterior+total;

        anterior+= total;

        //printf("%d %lld \n",i,sumatoria[i]);

    }

}

long long calculo_menor(int i){

     return sumatoria[i] + sumatoria[n-2]-sumatoria[i+1];

}

int main(){

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            scanf("%d",&arr[i]);

        }

        if(n%2==0){

            solution = -1;

            calculos(1);

            calculos(2);

            menor = min(sumatoria[n-2], sumatoria[n-3]);


           /* for(int i=0;i<n;i++){

                printf("%d %lld \n",i,sumatoria[i]);

            }
            printf("%lld %lld\n",sumatoria[n-2], sumatoria[n-3]);
            printf("\n");*/

            for(int i=1;i<n-2;i+=2){

                long long aux = calculo_menor(i);

                //printf("%d %lld\n",i,menor);

                menor = min(menor, aux);

            }

            solution = menor;

        }
        else{

            calculos(1);

            solution = sumatoria[n-2];

        }
         printf("%lld\n",solution);

    }


    return 0;
}
