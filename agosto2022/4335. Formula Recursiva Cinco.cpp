#include<bits/stdc++.h>

using namespace std;

int f(int n,int m){

    if(n==1){
        return -1*f(n-2,m);
    }
     if(n>=3){
        return 2+f(n-1,m);
    }
    if(n==2){
        return 2*m;
    }
}

int main(){

    int n,m;

    scanf("%d %d",&n,&m);

    printf("%d\n",f(n,m));


    return 0;
}
