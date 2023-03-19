#include<bits/stdc++.h>

using namespace std;

int t,
    n,
    cont_even,
    cont_odd,
    aux;

int main(){

    scanf( "%d",&t);
    
    while(t--){
        cont_even = cont_odd = 0;
        cin>>n;

        for(int i=0; i<n; i++){
            cin>>aux;
            if(aux%2==0){
                cont_even+=aux;
            }
            else{
                cont_odd+=aux;
            }
        }
        
        if(cont_even>cont_odd){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    
    }

    return 0;
}