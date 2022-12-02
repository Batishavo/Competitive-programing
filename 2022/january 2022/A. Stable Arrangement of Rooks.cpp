#include<bits/stdc++.h>
using namespace std;
bool use_rooks(int n, int rooks){
    if(n%2==0){
        return (n/2)>=rooks;
    }
    return((n+1)/2)>=rooks;

}
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        int n,rooks;
        scanf("%d %d",&n,&rooks);
        if(use_rooks(n,rooks)){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(j%2!=0 && i%2!=0 && i==j && rooks>0){
                        printf("R ");
                        rooks--;
                    }
                    else{
                        printf(". ");
                    }
                }
                printf("\n");
            }

        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
