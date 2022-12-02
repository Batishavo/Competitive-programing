#include <bits/stdc++.h>

using namespace std;

int t,
    n,
    c,
    total;

int main(){
    scanf("%d ",&t);
    vector<int> m(105,0);
    while(t--){
        scanf("%d %d",&n,&c);
        for(int i=0; i<n; i++){
            int aux;
            scanf("%d",&aux);
            m[aux]++;
        }

        for(int i=1;i<=100;i++){
            total += min(c,m[i]);
        }
        cout<<total<<endl;
        total =0;
        m=vector<int>(105,0);
    }
}