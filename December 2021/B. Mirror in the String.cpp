#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        int n;
        string cad,lexi="";
        cin>>n>>cad;
        for(int i=1;i<n;i++){
            if(cad[i]<=cad[i-1]){
                lexi+=cad[i-1];
            }
            else{
                break;
            }
        }
        string aux=lexi;
        reverse(aux.begin(),aux.end());
        cout<<lexi<<aux<<endl;
    }
    return 0;
}
