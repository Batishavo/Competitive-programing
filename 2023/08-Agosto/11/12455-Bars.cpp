#include<bits/stdc++.h>

using namespace std;

bool flag;

bool memo[25];

void  dp(int num,int pos,int n,int arr[]){

    //cout<<num<<endl;
    if(flag){
        return;
    }

    if(num==0){
        flag = true;
    }
    if(pos>=n){
        return ;
    }

    for(int i=pos;i<n;i++){
        if(num-arr[i]>=0 && memo[i]==0){
            memo[i]=1;
            dp(num-arr[i],i+1,n,arr);
            memo[i]=0;
        }
    }
    return;
}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int test;
    int n;
    int k;

    int arr[25];

    cin>>test;

    while(test--){
        
        cin>>k>>n;

        flag = false;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            memo[i]=0;
        }
        dp(k,0,n,arr);
        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }

    return 0;
}