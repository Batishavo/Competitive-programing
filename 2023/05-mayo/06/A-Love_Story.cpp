#include<bits/stdc++.h>

using namespace std;

string codeforces="codeforces",
    cad;

int t;

int igual(){
    int num=0;
    for(int i=0; i<10;i++){
        if(cad[i]!=codeforces[i]){
            num++;
        }
    }
    return num;
}

int main(){
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    cin>>t;
    while(t--){
        cin>>cad;
        cout<<igual()<<endl;
    }

    return 0;
}