#include<bits/stdc++.h>

using namespace std;

string cad;

int k,
    cad_size;

bool flag  = true;

char memo['z'+10];

bool posible(int ini){
    int impar = 0;
    for(int i=ini;i<ini+cad_size;i++){
        memo[cad[i]]++;
    }
    for(int i='a';i<='z';i++){
        if(memo[i]%2==1){
            impar++;
        }
        memo[i]=0;
    }
    return 
        (impar==1 && cad_size%2==1)|| 
        (impar==0 && cad_size%2==0)
    ;
}

int main(){

    cin>>cad>>k;
    //sort(cad.begin(), cad.end());
    cad_size=cad.size()/k;
    //cout<<cad<<endl;
    if(cad.size()%k!=0){
        flag = false;
    }
    for(int i=0;i<cad.size();i+=cad_size){
        if(!flag){
            break;
        }
        flag=posible(i);
    }

    if(flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}