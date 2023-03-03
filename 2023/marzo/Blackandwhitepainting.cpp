#include<bits/stdc++.h>

using namespace std;

int n,m,pos;

int main(){

    while(scanf("%d %d %d",&n,&m,&pos)){
        if(n==0 && m==0 && pos==0){
            break;
        }
        pos=!pos;
        n-=pos;
        m-=pos;
        printf("%d\n",(n/8)*(m/8));
    }

    return 0;
}