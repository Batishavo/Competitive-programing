#include<bits/stdc++.h>

using namespace std;

int n,
    cont,
    aux,
    sum;

int main(){
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    while(cin>>n){
        if(n==0){
            break;
        }
        sum=0;
        for(int i=0; i<n; i++){
            cin>>aux;
            if(aux>0){
                sum++;
            }
            else{
                sum--;
            }
        }
        printf("Case %d: %d\n",++cont,sum);
    }

    return 0;
}