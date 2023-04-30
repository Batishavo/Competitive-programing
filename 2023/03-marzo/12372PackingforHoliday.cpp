#include<bits/stdc++.h>

using namespace std;

int t,
    n,
    m,
    c,
    cont;

int main(){
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    scanf( "%d",&t);
    
    while(t--){
        
        cin>>n>>m>>c;

        if(n<=20 && m<=20 && c<=20){
            printf("Case %d: good\n",++cont);
        }
        else{
            printf("Case %d: bad\n",++cont);
        }
        
    
    }

    return 0;
}