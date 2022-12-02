#include<bits/stdc++.h>

using namespace std;

const int limit = 10e5+10;

int t,
    n,
    mayor,
    indice,
    arr[limit];

bool flag;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        mayor = INT_MIN;
        flag  = true;

        for(int i=0;i<n;i++){

            scanf("%d",&arr[i]);

            if(arr[i]>mayor){
                mayor  = arr[i];
                indice = i;
            }

        }

        for(int i=indice-1; i>=0; i--){

            if(arr[i]==arr[indice]){
                continue;
            }
            else{

                for(int j=i;j>=0;j--){
                    if(arr[j]>arr[j+1]){

                        flag=false;

                        break;
                    }
                }

                break;
            }

        }
        for(int i=indice+1; i<n;  i++){

             if(arr[i]==arr[indice]){
                continue;
            }
            else{

                for(int j=i;j<n;j++){
                    if(arr[j]>arr[j-1]){

                        flag=false;

                        break;
                    }
                }

                break;
            }

        }

        printf(flag?"YES\n":"NO\n");


    }

    return 0;
}
