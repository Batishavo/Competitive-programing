#include<bits/stdc++.h>
using namespace std;

int arr[300];
int main(){
    int test;

    scanf("%d",&test);

    while(test--){

        for(int i='A';i<='Z';i++){
            arr[i]=0;
        }

        int n,sum=0;

        string cad;

        cin>>n>>cad;

        for(int i=0;i<n;i++){

            if(arr[cad[i]]==0){
                sum+=2;

                arr[cad[i]]=1;
            }
            else{
                sum++;
            }

        }
        printf("%d\n",sum);

    }

    return 0;
}
