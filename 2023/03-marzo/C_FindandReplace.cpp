#include<bits/stdc++.h>

using namespace std;

int t,
    n;

string cad;

vector<int>v['z'+10];

void cleanup(){
    for(int i='a';i<='z';i++){
        v[i].clear();
    }
}

bool posible(){
    for(int i='a';i<='z';i++){
        if(v[i].size()>=2){
            int aux=v[i][0]%2;
            for(int j=1;j<v[i].size();j++){
                if(v[i][j]%2!=aux){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    scanf( "%d",&t);
    
    while(t--){
    
        cin>>n>>cad;
        cleanup(); 
        for(int i=0;i<n;i++){
            v[cad[i]].push_back(i);
        }

        if(posible()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}