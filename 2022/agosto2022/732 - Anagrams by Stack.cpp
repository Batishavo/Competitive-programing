#include<bits/stdc++.h>

using namespace std;

string source,
       target;

int n;

void cadenas(string cad,int stak,int i,int j){

        cout<<stak<<" "<<source[i]<<" "<<i<<" "<<target[j]<<" "<<j<<endl;
        cout<<cad<<endl;
        if(cad.size()==n*2){

            cout<<"--"<<cad<<endl;
        }

        if(i<n){

            cadenas(cad+'i',stak+1,i+1,j);
        }

        if(stak>0  ){

            cadenas(cad+'o',stak-1,i,j+1);

        }



}

int main(){

    while( getline(cin,source) ){

        getline(cin,target);

        n=source.size();

        cout<<'['<<endl;
        cadenas("",0,0,0);
        cout<<']'<<endl;

    }

    return 0;

}
