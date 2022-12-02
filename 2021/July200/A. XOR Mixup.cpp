#include<bits/stdc++.h>

using namespace std;

int arr[150];

int main(){

    int test;

    scanf("%d",&test);

    while(test -- ){

        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){

            scanf("%d",&arr[i]);
        }
        for(int i=0;i<n;i++){
            int actual=0;
            for(int j=0;j<n;j++){
                if(j==i){
                    continue;
                }
                actual = (actual^arr[j]);
                //cout<<actual<<endl;
            }
            if(actual==arr[i]){

                printf("%d\n",arr[i]);
                break;
            }

        }

    }


    return 0;
}
