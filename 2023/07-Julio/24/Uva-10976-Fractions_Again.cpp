#include<bits/stdc++.h>

using namespace std;

int compute_fraction(int n,int y){

    if((n*y)%(y-n)==0){
        return (n*y)/(y-n);
    }

    return -1;

}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;

    vector<pair<int,int>> fractions;

    while(cin>>n){

        fractions.clear();

        for(int i=n+1;i<=2*n;i++){
            int num = compute_fraction(n,i);
            if(num!=-1){
                fractions.push_back({num,i});
            }
        }

        cout<<fractions.size()<<endl;

        for(int i=0;i<fractions.size();i++){
            printf("1/%d = 1/%d + 1/%d\n",n,fractions[i].first,fractions[i].second);
        }
    }
    

    return 0;
}