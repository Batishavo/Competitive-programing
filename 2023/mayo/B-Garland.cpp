#include<bits/stdc++.h>

using namespace std;

const int limit = 'z'+10;

string cad_n,
    cad_m;

int used[limit];

int cont;

bool flag = true;

int main(){

    cin>>cad_n>>cad_m;
    
    for(int i=0; i<int(cad_n.size());i++){
        used[cad_n[i]]++;
    }
    for(int i=0; i<int(cad_m.size());i++){
        if(used[cad_m[i]]==0){
            flag = false;
            break;
        }
    }
    for(int i=0; i<cad_m.size();i++){
        if(used[cad_m[i]]>0){
            cont++;
            used[cad_m[i]]--;
        }
    }
    if(!flag){
        cout<<-1<<endl;
    }
    else{
        cout<<cont<<endl;
    }
    return 0;
}