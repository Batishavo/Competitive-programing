#include<bits/stdc++.h>

using namespace std;

string cad;

list<char> texto;
list<char>::iterator it;


int main(){

    while( getline(cin,cad) ){

        texto.clear();

        it = texto.begin();

        for(int i=0;i<cad.size();i++){

            if(cad[i]=='[' ){

                it = texto.begin();

            }
            else if(cad[i]==']'){

                it = texto.end();
            }
            else{
                texto.insert(it,cad[i]);
            }

        }

        //cout<<"-------";

        for(auto x: texto){

            cout<<x;

        }
        cout<<endl;


    }
    return 0;
}

