#include<bits/stdc++.h>

using namespace std;

const int limit = (10e6)+10;

int t,n;
string cad;
long long cont;

int main(){
    cin>> t;
    while(t--){
        cont=0;
        cin>>n>>cad;

        for(int i=0;i<n;i++){

            if(cad[i]=='0'){
                cad[i]='1';
                cont+=i+1;

                for(int j=(i+1)*2;j<=n;j+=i+1){
                    if(cad[j-1]=='0'){
                        cad[j-1]='1';
                        cont+=i+1;
                    }
                    else break;
                }
            }


        }

        cout<<"--"<<cont<<endl;
    }

    return 0;
}