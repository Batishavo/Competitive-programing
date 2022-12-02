#include<bits/stdc++.h>
using namespace std;

int t,n,m,c;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d %d",&n,&m,&c);

        int num=(abs(m-c))+c;

        if(n<num){
            printf("1");
        }
        else if(num<n){
            printf("2");
        }
        else{
            printf("3");
        }
        printf("\n");

    }

    return 0;
}
