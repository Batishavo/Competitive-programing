#include<bits/stdc++.h>

using namespace std;

const int limit= 10e5+10;

int n,m,k,p1,p2;

long long arr[limit],
    operations[limit][8],
    sum[limit][5];

int main(){

    cin>>n>>m>>k;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=m;i++){
        cin>>operations[i][0]>>operations[i][1]>>operations[i][2];
    }
    for(int i=0;i<k;i++){
        cin>>p1>>p2;
        operations[p1][3]++;
        operations[p2+1][3]--;
    }
    for(int i=1;i<=m;i++){
        operations[i][4]=operations[i-1][4]+operations[i][3];
        operations[i][5]=operations[i][2]*operations[i][4];
    }
    //cout<<"----"<<endl;
    for(int i=1;i<=m;i++){
       // printf("%lld %lld\n",operations[i][0],operations[i][1]+1);
        sum[operations[i][0]]  [0]+=operations[i][5];
        sum[operations[i][1]+1][0]-=operations[i][5];
    }
    for(int i=1;i<=n;i++){
        sum[i][1]=sum[i-1][1]+sum[i][0];
    }
    for(int i=1;i<=n;i++){
        cout<<sum[i][1]+arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}