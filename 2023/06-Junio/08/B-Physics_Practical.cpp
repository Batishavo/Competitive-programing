#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int n,
    memo[limit],
    sum[limit],
    answer=INT_MAX,
    minimo=INT_MAX,
    mayor=INT_MIN;

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d",&aux);
        memo[aux]++;
        minimo=min(minimo,aux);
        mayor=max(mayor,aux);
    }

    for(int i=minimo;i<=mayor;i++){
        sum[i]=sum[i-1]+memo[i];
    }

    for(int i=minimo;i<=mayor;i++){
        if(i*2>mayor){
            answer=min(answer,sum[i-1]);
        }
        else{
            answer=min(answer,sum[mayor]-sum[i*2]+sum[i-1]);
        }
    }

    cout<<answer<<endl;

    return 0;
}