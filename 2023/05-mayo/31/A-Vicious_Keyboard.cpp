#include<bits/stdc++.h>

using namespace std;

string cad;

int mayor = 0;

int count_vk(string str){

    int num = 0;

    for(int i=1;i<str.size();i++){
        if(str[i]=='K' && str[i-1]=='V'){
            num++;
        }
    }

    return num;

}

int main(){

    cin>>cad;

    mayor = count_vk(cad);

    for(int i=0;i<cad.size();i++){
        string aux = cad;
        if(aux[i]=='K'){
            aux[i]='V';
        }
        else{
            aux[i]='K';
        }
        mayor = max(mayor,count_vk(aux));
    }

    cout<<mayor<<endl;

    return 0;
}