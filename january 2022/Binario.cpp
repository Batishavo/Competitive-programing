#include<bits/stdc++.h>
using namespace std;
void imprime_binario(int n){
    if(n>=2){
        imprime_binario(n/2);
        printf("%d",n%2);
    }
    else{
        printf("%d",n);
    }
}
int main(){
    imprime_binario(100);
    return 0;
}
