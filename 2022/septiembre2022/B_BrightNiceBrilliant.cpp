#include<bits/stdc++.h>

using namespace std;

int t,n;

int main(){

    //cout<<"HolaMundo"<<endl;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(i==j || j==1){
                    printf("%d ",1);
                }
                else{
                    printf("%d ",0);
                }
            }
            printf("\n");
        }

    }

    return 0;
}