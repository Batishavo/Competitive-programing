#include <bits/stdc++.h>
using namespace std;
const int limN = 2000;
const int limM = 40;
const long long mod = 1e9 + 7;

long long dp[limM][limN];
bool mark[limM][limN];
int n,m;

long long solve(int pos, int ant){
    if(pos == m*2){
        return 1;
    }
    if( mark[pos][ant] ){
        return dp[pos][ant];
    }

    mark[pos][ant] = 1;
    int ini = ant;
    if(ini == 0) ini = 1;
    long long res = 0;
    for(int i=ini; i<=n; i++){
        res += solve(pos+1,i);
        res %= mod;
    }
    return dp[pos][ant] = res;
}

int main (){

    scanf("%d%d",&n,&m);
    printf("%d",solve(0,0));

    return 0;
}