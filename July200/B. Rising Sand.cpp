#include<bits/stdc++.h>

using namespace std;

const int limit=20e5+30;

int arr[limit];

int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        int n,k,cont=0;

        scanf("%d %d",&n,&k);

        for(int i=0;i<n;i++){

            scanf("%d",&arr[i]);

        }

        if(k>1){
            for(int i=1;i<n-1;i++){

                if(arr[i]>arr[i-1]+arr[i+1]){
                    cont++;
                }
            }

            printf("%d\n",cont);
        }

        else{

            if(n%2==0)
                n--;

            printf("%d\n",n/2);


        }

    }

    return 0;
}
