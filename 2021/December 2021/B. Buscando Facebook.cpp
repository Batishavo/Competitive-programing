#include<bits/stdc++.h>
using namespace std;
string facebook="facebook";
bool is_facebook(string cad){
    int pos=0;
    for(int i=0;i<cad.length();i++){
        if(cad[i]==facebook[pos]){
            pos++;
        }
        if(pos==facebook.length()){
            return true;
        }
    }
    return false;
}
int main(){
    int test;
    scanf("%d",&test);
    for(int k=1;k<=test;k++){
        string cad;
        cin>>cad;
        bool can=is_facebook(cad);
        if(can){
            printf("Case #%d: YES\n",k);
        }
        else{
             printf("Case #%d: NO\n",k);
        }
    }

    return 0;
}
