#include<bits/stdc++.h>

using namespace std;

const int limit = (2*10e5)+10;

int test,
    n,
    num = 0,
    arr[limit],
    bucket[limit];

void clean(){

    for(int i=0;i<=n;i++){

        bucket[i]=0;
    }

}

int main(){

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int aux;

            scanf("%d",&arr[i]);


        }

        for(int i=n-1;i>=0;i--){

            if(bucket[arr[i]]==0){

                bucket[arr[i]]=1;

            }
            else{
                num=i+1;

                break;

            }


        }

        printf("%d\n",num);

        num=0;

        clean();


    }

    return 0;
}
