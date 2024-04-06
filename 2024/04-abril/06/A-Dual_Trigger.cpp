#include<bits/stdc++.h>

using namespace std;

class Solution{
public:

    int countZeros(int n,string cad){
        int cont = 0;
        for(int i=0;i<n;i++){
            if(cad[i]=='1'){
                cont++;
            }
        }
        return cont;
    }

    bool isAdjacent(int n,string cad,int cont){
        if(cont!=2){
            return true;
        }
        for(int i=0;i<n-1;i++){
            if(cad[i]=='1'&&cad[i+1]=='1'){
                return false;
            }
        }
        return true;
    }

    bool isPosible(string cad){
        int n = cad.size();
        int cont = countZeros(n,cad);
        bool areTwo = isAdjacent(n,cad,cont);

        return cont%2==0 && areTwo;
    }
};

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;
    int n;
    string cad;
    Solution answer;

    cin>>t;

    while(t--){
        cin>>n>>cad;
        cout<<(answer.isPosible(cad)?"YES":"NO")<<endl;
    }
    

    return 0;
}