#include<bits/stdc++.h>

using namespace std;

const int limit = 10e5+10;

vector<int>squares;

int t,
    n,
    arr[limit];

void perfectSquares(){

    int num=1,
        ant=num;

    squares.push_back(0);

    while(ant<=limit){

        ant=num*num;

        squares.push_back(ant);

        num++;

    }

}

int buscqueda(int num){

    int aux=num*2;

    for(int i=0;i<squares.size();i++){

        if(squares[i]==aux){
            return squares[i];
        }
        if(squares[i]>aux){
           return squares[i-1];
        }

    }
    return 0;
}

void inidicea(int num){

    int aux = buscqueda(num-1),
        cont = 0;

    //printf("%d\n",aux);

    for(int i=aux-num+1;i<num;i++){
        arr[i]=num-cont-1;
        cont++;
    }

    /*for(int i=0;i<n;i++){

        printf("%d ",arr[i]);
    }
    printf("\n");*/
    if(num-cont>0){

       inidicea(num-cont);
    }

}
int main(){

    perfectSquares();

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        inidicea(n);

        for(int i=0;i<n;i++){

            printf("%d ",arr[i]);
        }
        printf("\n");

    }

    return 0;
}
