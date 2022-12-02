#include<bits/stdc++.h>

using namespace std;

int n,t,
    arr[300];

string cad;

int main(){

    scanf("%d",&t);

    while(t--){

        cin>>n>>cad;

        for(int i=0;i<n;i++){

            arr[cad[i]]++;

        }

        bool flag=true;

        for(int i=min('a','A');i<=max('z','Z');i++){

            if( i=='T' ||
                i=='i' ||
                i=='m' ||
                i=='u' ||
                i=='r'
               ){

               if(arr[i]==1){
                continue;
               }
               else{
                flag=false;
               }

            }
            else if(arr[i]!=0){
                flag=false;
            }

        }

        printf((flag==true)?"YES\n":"NO\n");

        for(int i=0;i<n;i++){

            arr[cad[i]]=0;

        }

    }


    return 0;
}
