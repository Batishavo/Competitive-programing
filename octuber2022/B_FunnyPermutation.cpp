#include<bits/stdc++.h>

using namespace std;

int t,n;

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>n;
        
        if(n==1 || n==3){
            cout<<-1<<endl;
            continue;
        }

        int cont=1;

        for(int i=n;i>=1;i--){

            if(i == cont){
                
                for(int j=1;j<=cont;j++){
                    cout<<j<<" ";
                }

                break;
            }
            cout<<i<<" ";
            cont++;
        }
        cout<<endl;
    }

    return 0;
}