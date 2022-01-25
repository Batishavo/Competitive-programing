#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        string cad;
        cin>>cad;
        sort(cad.begin(),cad.end());
        cout<<cad<<endl;
    }
    return 0;
}
