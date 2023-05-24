#include<bits/stdc++.h>

using namespace std;

int n,
    t,
    cont;
string cad,
    n1,
    n2;

int main(){

    scanf( "%d",&t);
    
    while(t--){
        
        cin>>n>>cad;
        n1=n2="";
        cont=0; 
        for(int i=0;i<n/2;i++){
            n1+=cad[i];
        }
        for(int i=n-1;i>=(n/2)+(n%2);i--){
            n2+=cad[i];
        }
        //cout<<n1<<" -- "<<n2<<endl;
        int ant=0;
        for(int i=0;i<n/2;i++){
            if(n1[i]!=n2[i] && ant==0){
                ant=1;
                cont++;
            }
            if(n1[i]==n2[i]){
                ant=0;
            }
        }
        printf(cont<=1?"YES\n":"NO\n");
    }

    return 0;
}