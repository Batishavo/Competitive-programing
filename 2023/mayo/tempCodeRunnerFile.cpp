#include<bits/stdc++.h>

using namespace std;

vector<string>palabras;

string cadena,
    alfabeto;

bool estan_ordenadas = true;

bool es_menor(char menor,char mayor){
    for(int i=0;i<alfabeto.size();i++){
        if(alfabeto[i]==menor){
            return true;
        }
        if(alfabeto[i]==mayor){
            break;
        }
    }
    return false;
}

bool cadena_odenada(string valorMayor,string valorMenor){

    int ciclo = min(valorMenor.size(),valorMayor.size());

    for(int i=0;i<ciclo;i++){
        char menor = valorMenor[i],
            mayor = valorMayor[i];
        if (menor == mayor){
            continue;
        }
        if(es_menor(menor,mayor)){
            return true;
        }
        else{
            return false;
        }
    }
    return valorMayor.size()>=valorMenor.size();
}

int main(){
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    while(cin>>cadena){
        if(cadena == "0"){
            break;
        }
        palabras.push_back(cadena);
    }
    cin>>alfabeto;
    for(int i=1;i<palabras.size();i++){
        if(!cadena_odenada(palabras[i],palabras[i-1])){
            estan_ordenadas = false;
            break;
        }
    }

    if(estan_ordenadas){
        cout<<"Estan ordenadas"<<endl;
    }
    else{
        cout<<"No estan ordenadas"<<endl;
    }

    return 0;
}