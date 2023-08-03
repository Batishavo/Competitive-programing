#include<bits/stdc++.h>

using namespace std;

const int limit = 10e5+10;

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;
    int n;    
    int cont = 0;
    int arr[limit];

    cin>>t;

    while(t--){
        cin>>n;
        cont = 0;
        for(int i=1;i<=n;i++){
            int aux;
            cin>>aux;
            if(aux==i){
                cont++;
            }
        }
        cout<<cont/2+cont%2<<endl;
    }

    return 0;
}