#include<bits/stdc++.h>

using namespace std;

const int limit = 2010;

int n,
    arr[limit],
    mayor= INT_MIN;

int escalones(int i){

    if(arr[i]!=0){

        return escalones(arr[i])+1;

    }
    return 1;


}


int main(){

    scanf("%d",&n);

    for(int i=1;i<=n;i++){

        scanf("%d",&arr[i]);

    }

    for(int i=1;i<=n;i++){

        int aux = escalones(arr[i]);

        //printf("%d")

        mayor=max(mayor,aux);

    }

    printf("%d\n",mayor);

    return 0;
}
