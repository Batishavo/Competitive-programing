#include<bits/stdc++.h>

using namespace std;

int arr[200];
int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        int n;

        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        bool flag=true;

        for(int i=1;i<n;i++){
            bool flag2=false;
            for(int j=i-1;j>=0;j--){

                if(arr[i]%arr[j]==0){
                    flag2=true;
                    break;
                }

            }
            flag=flag2;
            if(flag2==false){
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}
