#include<bits/stdc++.h>

using namespace std;

int t,arr[40],maximo,pos,n;

int main(){

    scanf("%d",&t);

    while(t--){

        maximo=INT_MIN;
        pos=0;

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            scanf("%d",&arr[i]);

            if(arr[i]>maximo){
                maximo=arr[i];
                pos=i+1;
            }


        }

        printf("%d\n",pos);


    }



    return 0;
}
