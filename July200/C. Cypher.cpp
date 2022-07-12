#include<bits/stdc++.h>
using namespace std;

int arr[300];

int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            scanf("%d",&arr[i]);
        }
        for(int i=0;i<n;i++){

            int moves;
            string cad;
            cin>>moves>>cad;

            for(int j=0;j<moves;j++){

                if(cad[j]=='D'){
                    arr[i]++;
                }
                else{
                    arr[i]--;
                    if(arr[i]<0){
                        arr[i]=9;
                    }
                }

            }
        }
        //printf("--");
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]%10);
            arr[i]=0;
        }
        printf("\n");

    }

    return 0;
}
