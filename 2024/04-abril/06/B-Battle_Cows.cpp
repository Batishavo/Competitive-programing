#include<bits/stdc++.h>

using namespace std;

class BattleCows{
public:
    int answer(int n,vector<long long> &cows,long power){
        
        int cont = 0;
        int maxWins = 0;
        long long champion = cows[0];

        for(int i=0;i<n-1;i++){
            champion=max({champion,cows[i]});
            if(champion>power){
                cont = 0;
            }
            else if(cows[i]<power){
                cont++;
            }
            else{
                cont=0;
            }
            //cout<<cont<<" "<<maxWins<<endl;
            maxWins=max(cont,maxWins);
        }

        maxWins=(cont,maxWins);
        return maxWins;
    }
};

int main(){

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int t;
    int n;
    int index;
    int power;
    vector<long long> cows;
    BattleCows battleCows;
    
    cin>>t;
    
    while(t--){
        cin>>n>>index;
        for(int i=0;i<n;i++){
            if(i==index-1){
                cin>>power;
                continue;
            }
            int cow;
            cin>>cow;
            cows.push_back(cow);
        }
        cout<<battleCows.answer(n,cows,power)<<endl;
        cows.clear();
    }
    

    return 0;
}