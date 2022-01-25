#include<bits/stdc++.h>
using namespace std;
void cadena(int n,int c,string cad,int pos){
    if(pos==n){
        cout<<cad<<endl;
        return;
    }
    for(int i='a';i<'a'+c;i++){
        char word=i;
        cadena(n,c,cad+word,pos+1);
    }
}
int main(){
    cadena(3,3,"",0);
    return 0;
}
