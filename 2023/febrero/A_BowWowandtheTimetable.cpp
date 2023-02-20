#include<bits/stdc++.h>

using namespace std;

string cad;
int cont=0;

int main(){

    cin>>cad;
    bool flag=0,
        tmp=1;
    for(int i=cad.size()-1;i>=0;i--){
        if(cad[i]=='1' && i!=0){
            flag=1;
        }
        if(i==0){
            if(flag && tmp){
                cont++;
            }
        }
        else{
            if(tmp==1){
                cont++;
            }
        }
        
        tmp=!tmp;
        
    }
    cout<<cont<<endl;

    return 0;
}