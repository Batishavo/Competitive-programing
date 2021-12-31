#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        int n;
        string cad,lexi="";
        cin>>n>>cad;
        lexi+=cad[0];
        for(int i=1;i<n;i++){
            if(cad[i]<=lexi[i-1]){
                lexi+=cad[i];
            }
            else{
                break;
            }
        }
        string aux=lexi;
        reverse(aux.begin(),aux.end());
        lexi+=aux;
        cout<<lexi<<endl;
    }
    return 0;
}
