#include<bits/stdc++.h>

using namespace std;

int n;
int k;
int m;

long long dp[60][60][60];

long long BC(bool ant,int tam,int sum_m,int sum_k){

    if(sum_k>k || sum_m>m){
        return 0;
    }

    if(tam==n ){
        if(sum_m==m){
            //cout<<cad<<endl;
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[tam][sum_m][sum_k]==-1){
        dp[tam][sum_m][sum_k]=BC(ant,tam+1,sum_m,sum_k+1) + BC(!ant,tam+1,sum_m+1,1);
    }


    return dp[tam][sum_m][sum_k];

}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    while(cin>>n>>m>>k){
        memset(dp,-1,sizeof dp);
        cout<<BC(1,1,1,1)<<endl;
    }

    return 0;
}