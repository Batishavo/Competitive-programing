#include<bits/stdc++.h>

using namespace std;

int t,
    n,
    aux,
    maximo,
    memo[1010];

void clear(){
    for(int i=0; i<=1000;i++){
        memo[i] = 0;
    }
}

int main(){

    scanf( "%d",&t);
    
    while(t--){
        
        cin>>n;
        maximo=-1;
        clear();
        for(int i=1; i<=n;i++){
            
            cin>>aux;
            memo[aux]=i;
        }

        for(int i=1;i<=1000;i++){
            if(memo[i]==0){
                continue;
            }
            for(int j=1;j<=1000;j++){
                if(memo[j]==0){
                    continue;
                }

                if(__gcd(j,i)==1){
                    maximo=max(maximo,memo[j]+memo[i]);
                }

            }
        }
        //cout<<"--";
        cout<<maximo<<endl;

    }
    

    return 0;
}