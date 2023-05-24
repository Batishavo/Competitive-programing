#include<bits/stdc++.h>

using namespace std;

int t,cont1,cont2;

string cad="",cad2="",aux;

int main(){

    cin>>t;
    for(int i=0;i<t;i++){
        cin>>aux;
        if(cad=="" || cad==aux){
            cad=aux;
            cont1++;
        }
        else{
            cad2=aux;
            cont2++;
        }
    }
    if(cont1>cont2){
        cout<<cad<<endl;
    }
    else{
        cout<<cad2<<endl;
    }

    return 0;
}