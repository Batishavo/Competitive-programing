#include<bits/stdc++.h>

using namespace std;

int t,n;

int arr[100];
int main(){

    scanf("%d",&t);

    while(t--){

       scanf("%d",&n);

       if(n%2==0){
        for(int i=n-2;i>=2;i--){
            printf("%d ",i);
        }
        printf("1 %d %d",n-1,n);
       }
       else{
        printf("%d ",n-1);
        for(int i=n-3;i>=2;i--){
            printf("%d ",i);
        }
        printf("1 %d %d",n-2,n);
       }


       printf("\n");
    }

    return 0;
}
