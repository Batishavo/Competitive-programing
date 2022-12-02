#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,a,b;
    scanf("%d",&t);

    while(t--){

        scanf("%d %d %d",&n,&a,&b);

        if((a==0 && b==0) || (a>0 && b>0) ){
            printf("-1");
        }
        else if(a>0 && (n-1)%a==0){
            for(int i=1;i<=n-1;){

                for(int j=0;j<a;j++){
                    printf("%d ",i);
                }
                i+=a+1;
            }
        }
        else if(b>0 && (n-1)%b==0){
            for(int i=1;i<=n-1;){

                for(int j=0;j<b;j++){
                    printf("%d ",i);
                }
                i+=b+1;
            }
        }
        else{
            printf("-1");
        }
        printf("\n");
    }


    return 0;
}
