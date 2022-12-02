#include<bits/stdc++.h>

using namespace std;
const int limit =10e5+10;

long long arr[limit];

int num(int i,int l,int r){

    int dif=(l%i),
        first;
    if(dif==0){
        first=0;
    }
    else{
        first=i-dif;
    }
    if(l+first<=r){

        return l+first;
    }


    return -1;
}
int main(){
    int test;

    scanf("%d",&test);

    while(test--){

        int n;

        long long l,
                  r;

        bool flag=true;

        scanf("%d %lld %lld",&n,&l,&r);

        for(int i=1;i<=n;i++){

            long long actual=num(i,l,r);

            if(actual==-1){
                flag=false;
                break;
            }
            arr[i]=actual;

        }
        //printf("--");
        if(flag){


            printf("YES\n");
            for(int i=1;i<=n;i++){
                printf("%lld ",arr[i]);
            }
            printf("\n");

        }
        else{
            printf("NO\n");
        }

    }

    return 0;
}
