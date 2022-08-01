#include<bits/stdc++.h>

using namespace std;


int arr[15]= {1,2,3,4,5,6,7,8,9},
    use[15],
    test,
    n;

int main(){

    scanf("%d",&test);

    //test=46;
    while(test--){

        scanf("%d",&n);
        //n=test;
        for(int i=9;i>=1;i--){

            if(n>=i){

                n-=i;
                use[i]=1;
            }

            if(n==0){
                break;
            }


        }
        //printf("--");
        for(int i=0;i<=9;i++){

            if(use[i]==1){

                printf("%d",i);
                use[i]=0;
            }

        }
        printf("\n");

    }

    return 0;
}


