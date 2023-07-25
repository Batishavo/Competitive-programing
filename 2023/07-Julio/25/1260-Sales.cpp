#include<bits/stdc++.h>

using namespace std;

const int limit = 10e3+10;

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int answer;
    int n;
    int queries;
    int sales[limit];

    cin>>queries;

    while(queries--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>sales[i];
        }
        
        answer=0;

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(sales[j]<=sales[i]){
                    answer++;
                }
            }
        }

        cout<<answer<<endl;
    }

    return 0;
}