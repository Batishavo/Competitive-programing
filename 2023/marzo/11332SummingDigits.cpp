#include<bits/stdc++.h>

using namespace std;

string cad;

string f(string cad){
    if(cad.size()<=1){
        return cad;
    }
    int num=0;
    for(int i=0;i<cad.size();i++){
        num+=cad[i]-'0';
    }
    return f(to_string(num));
}

int main(){
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    while(cin>>cad){
        if(cad=="0"){
            break;
        }
        cout<<f(cad)<<endl;
    }

    return 0;
}