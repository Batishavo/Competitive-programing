#include<bits/stdc++.h>

using namespace std;

int cont=0,
    num1,
    num2;

char sign;
char cad[100];

int conver(){
    int num=0,
        pos=1;
    for(int i=strlen(cad)-1; i>=0;i--){
        num+=(cad[i]-'0')*pos;
        pos*=10;
    }
    return num;
}

int main(){
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    while(scanf("%d%c%d=%s",&num1,&sign,&num2,cad) == 4){
        if(cad[0]!='?'){
            int res=conver();
            if(sign=='+' && num1+num2==res){
                cont++;
            }
            if(sign=='-' && num1-num2==res){
                cont++;
            }
        }
    }
    cout<<cont<<endl;
    return 0;
}