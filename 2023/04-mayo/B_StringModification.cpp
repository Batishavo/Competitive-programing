#include<bits/stdc++.h>

using namespace std;

int t,
    n,
    best_num;

string cad,
    best_cad;

void generate_cad(int num){

    string prefix=cad.substr(num-1,n-num+1),
        suffix = cad.substr(0,num-1);

    if(n%2 ==num%2){
        reverse(suffix.begin(),suffix.end());
    }
    string new_cad=prefix+suffix;
    if(new_cad<best_cad){
        best_cad=new_cad;
        best_num=num;
    }

}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>n>>cad;
        best_cad=cad;
        best_num=1;
        for(int i=2;i<=n;i++){
            generate_cad(i);
        }

        cout<<best_cad<<endl<<best_num<<endl;

    }   

    return 0;
}