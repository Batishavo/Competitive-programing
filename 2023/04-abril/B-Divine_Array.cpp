#include <bits/stdc++.h>

using namespace std;

const int limit_n     = 2010;

int n,
    q,
    t,
    memo  [limit_n],
    result[limit_n][limit_n];


void calcular(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            memo[result[i-1][j]]++;
        }
        for(int j=1;j<=n;j++){
            result[i][j]=memo[result[i-1][j]];
            //cout<<arr[j]<<" ";
        }
        //cout<<endl;
        for(int j=1;j<=n;j++){
            memo[j]=0;
        }
    }
    //cout<<endl;

}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    scanf("%d", &t);

    while (t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>result[0][i];
        }
        calcular();
        cin>>q;
        while(q--){
            int xi;
            long long ki;
            cin>>xi>>ki;
            if(ki>n){
                cout<<result[n][xi];
            }
            else{
                cout<<result[int(ki)][xi];
            }
            cout<<endl;
        }
    }

    return 0;
}