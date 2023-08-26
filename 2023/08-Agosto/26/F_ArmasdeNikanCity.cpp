#include<bits/stdc++.h>

using namespace std;

map<string,pair<int,int>>wepons;

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int power;
    int query;

    string cad;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>cad>>power;
        
        string tmp="";

        for(int i=0;i<cad.size()-1;i++){
            tmp+=cad[i];

            wepons[tmp].first++;
            wepons[tmp].second=max(power,wepons[tmp].second);
        }
    }

    cin>>query;

    for(int i=0;i<query;i++){
        cin>>cad;
        cout<<wepons[cad].first<<" "<<wepons[cad].second<<endl;
    }

    return 0;
}