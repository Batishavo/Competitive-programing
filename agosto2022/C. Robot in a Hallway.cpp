#include<bits/stdc++.h>

using namespace std;

const int limit = 2*10e5+10;

int test;

long long n,
          maximo = INT_MIN,
          cells[5][limit];

bool recorrido1(int i,int j,int acum,int fin_i,int fin_j){


    while(i!=fin_i && j!=fin_j){

        if(cells[i][j]<=acum){

            return false;

        }
        if(i==0 && j<n){

            j++;
        }
        else{
            j--;
        }
        if(j==n){
            j--;
            i=1;
        }
        acum++;
    }

    printf("A\n");
    return true;

}

bool recorrido2(int i,int j,int acum,int fin_i,int fin_j){

    while(i!=fin_i && j!=fin_j){

        if(cells[i][j]<=acum){

            return false;

        }
        if(i==0 && j==0){

            i++;
        }
        else if(i==1 && j<n-1){
            j++;
        }
        else{
            j--;
        }
        acum++;
    }
    printf("B\n");
    return true;

}

bool recorrido3(int acum){

    int i=0,
        tmp;

    for(int j=0;j<n;j++){

        if(j%2==0){
            i=0;
            tmp=1;
        }
        else{
            i=1;
            tmp=-1;
        }
        ///////////
        if(cells[i][j]<=acum ){
            acum++;

        }
        else{

            if(i==0){

                return recorrido1(0,j,acum,1,j);
            }
            else{
                return recorrido2(1,j,acum,0,j+1);
            }

        }
        if(cells[i+tmp][j]<=acum){
            acum++;
        }
        else{

            if(i==0){

                return recorrido1(0,j,acum,1,j);
            }
            else{
                return recorrido2(1,j,acum,0,j+1);
            }

        }

    }
    printf("C\n");
    return true;

}
bool recorrido(int time){

    if(recorrido1(0,0,time,1,0)|| recorrido2(0,0,time,0,1)
       || recorrido3(time)){

        return true;

    }

    return false;
}

int bynari(){

    long long  ini=0,
               fin=maximo;

    while(ini<fin){

       int mid  = ((fin+ini)/2)+1;
       bool flag = recorrido(mid);

       printf("--%d %d\n", mid,flag);

       if(flag){

        fin= mid-1;

       }
       else{

         ini = mid;
       }

    }

     printf("**%d\n",ini);
    return ini;
}

int main(){

    scanf("%d",&test);

    while(test--){

        scanf("%lld",&n);

        for(int i=0;i<2;i++){

            for(int j=0;j<n;j++){

                scanf("%lld",&cells[i][j]);

                if(cells[i][j]>maximo){
                    maximo=cells[i][j];
                }

            }

        }

        //printf("%d ",maximo);


        printf("!!%lld\n",bynari()+(n*2)-1);

        maximo = INT_MIN;
    }

    return 0;
}
