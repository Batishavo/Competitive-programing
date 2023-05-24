#include<bits/stdc++.h>

using namespace std;

const int limit = 110;

int t,
    n,
    maximo,
    actual;

bool arr[limit];

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    cin>>t;

    while(t--){
        maximo = 0;
        actual = 0;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<n; i++){
            if(arr[i]==0){
                actual++;
            }
            else{
                maximo = max(maximo,actual);
                actual = 0;
            }
        }
        maximo = max(maximo,actual);
        cout<<maximo<<endl;
    }
    

    return 0;
}