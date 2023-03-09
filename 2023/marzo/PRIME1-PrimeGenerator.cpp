#include<bits/stdc++.h>

using namespace std;

const int limit = 1000000000+100000+10;

bool memo[limit];

void criba(){
    memo[0]=1;
    memo[1]=1;
    for(int i=2;i<=limit;i++){
        if(memo[i]==0){
            cout<<i<<",";
            for(int j=i+i;j<=limit;j+=i){
                memo[j]=1;
            }
        }
    }
}

int main(){
    // freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    // cin>>x;
    cout<<"[";
    criba();
    cout<<"]\n";
    

    return 0;
}