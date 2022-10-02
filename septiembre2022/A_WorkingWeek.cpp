#include<bits/stdc++.h>

using namespace std;

int t,n;

int main(){

    scanf( "%d",&t);
    
    while(t--){
        cin>>n;

        // int a,b,c,menor=0;
        // for(int i=2; i<=n;i++){
        //     for(int j=i+2; j<=n; j++){
        //         for(int k=j+2; k<=n; k++){

        //             int uno=i,
        //                 dos=j-i,
        //                 tres=k-j;

        //             int sa=abs(uno-dos);
        //             int sb=abs(tres-uno);
        //             int sc=abs(tres-dos);
        //             int aux = min(sa,min(sb,sc));
        //             menor=max(menor,aux);
                    

                    
        //         }
        //     }
        // }
        // cout<<menor<<endl;
        cout<<(n/3)-2<<endl;
    }

    return 0;
}