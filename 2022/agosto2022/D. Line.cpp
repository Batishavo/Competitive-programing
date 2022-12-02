#include<bits/stdc++.h>

using namespace std;

const int limit=(2*10e5)+10;

int t,n,
    pI,pJ;

string cadActual,
       optima;

long long actual,
          maximo,
          sumAcutal[limit],
          sumMaximo[limit];

int main(){

    cin>>t;

    while(t--){

        cin>>n>>cadActual;

        for(int i=0;i<n;i++){

            if(cadActual[i]=='L'){
                actual+=(i+1)-1;
                sumAcutal[i]=(i+1)-1;
            }
            else if(cadActual[i]=='R'){
                actual+=n-(i+1);
                sumAcutal[i]=n-(i+1);
            }

            if(i+1<=n/2){
                maximo+=n-(i+1);
                sumMaximo[i]=n-(i+1);
            }
            else{
                maximo+=(i+1)-1;
                sumMaximo[i]=(i+1)-1;
            }


        }
        pI=1,pJ=n;
        int cont=0;

        while(true){

            while(sumAcutal[pI-1]==sumMaximo[pI-1]){
                if(pI>n/2){
                    break;
                }
                pI++;
            }
            while(sumAcutal[pJ-1]==sumMaximo[pJ-1]){
                if(pJ<=n/2){
                    break;
                }
                pJ--;
            }
            //////////
            if((pI>n/2 && pJ<=n/2) || cont==n) {
                break;
            }
            else if(pI>n/2){
                actual=actual-sumAcutal[pJ-1]+sumMaximo[pJ-1];
                printf("%lld ",actual);
                pJ--;
                cont++;
            }
            else if( pJ<=n/2){
                actual=actual-sumAcutal[pI-1]+sumMaximo[pI-1];
                printf("%lld ",actual);
                pI++;
                cont++;
            }
            else{
                if(sumMaximo[pJ-1]>sumMaximo[pI-1]){
                    actual=actual-sumAcutal[pJ-1]+sumMaximo[pJ-1];
                    printf("%lld ",actual);
                    pJ--;
                    cont++;
                }
                else{
                    actual=actual-sumAcutal[pI-1]+sumMaximo[pI-1];
                    printf("%lld ",actual);
                    pI++;
                    cont++;
                }
            }

        }

        for(int i=cont;i<n;i++){
            printf("%lld ",actual);
        }
        printf("\n");
         //printf("%d %d\n",pI,pJ);
        maximo=0;
        actual=0;
        for(int i=0;i<n;i++){
            sumAcutal[i]=0;
            sumMaximo[i]=0;
        }

    }


    return 0;
}
