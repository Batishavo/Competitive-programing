#include<bits/stdc++.h>

using namespace std;

int t,n,mayor;

string cad;

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>n>>cad;    
        for(int i=0;i<n;i++){
            mayor=max(mayor,(int)cad[i]);
        }
        //cout<<"--";
        cout<<mayor-'a'+1<<endl;
        mayor=0;
    }

    return 0;
}