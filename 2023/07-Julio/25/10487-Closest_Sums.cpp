#include<bits/stdc++.h>

using namespace std;

const int limit = 10e3+10;

int closests_sum(int num,vector<int> &integers,int n){
    int minimo = INT_MAX;
    int answer = -1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            int sum = integers[i]+integers[j];
            if(abs(sum-num)<minimo){
                minimo = abs(sum-num);
                answer = sum;
            }

        }
    }
    return answer;
}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int m;
    int actual_case=1;

    vector<int> intergers(limit);

    while(scanf("%d",&n)){
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&intergers[i]);
        }
        
        scanf("%d",&m);
        printf("Case %d:\n",actual_case++);
        for(int i=0;i<m;i++){
            int aux;
            scanf("%d",&aux);
            printf("Closest sum to %d is %d.\n",aux,closests_sum(aux,intergers,n));
        }

    }

    return 0;
}