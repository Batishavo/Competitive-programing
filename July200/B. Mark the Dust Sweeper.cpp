#include<bits/stdc++.h>

using namespace std;

const int limit = 2*10e5+10;

long long arr[limit];

long long cleaning(int n){

    long long cont = 0,
              aux  = 0;

    for(int i=n-2;i>=0;i--){

        if(arr[i]==0){
            aux++;
        }
        else{
            cont+= arr[i] + aux;
            aux=0;
        }


    }

    return cont;

}

int main(){

    long long cont;

    int test,
        n;

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int aux;

            scanf("%d",&arr[i]);

        }
        cont = cleaning(n);

        printf("%d\n",cont);


    }


    return 0;
}


