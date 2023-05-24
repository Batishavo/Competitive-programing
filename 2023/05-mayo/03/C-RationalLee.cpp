#include<bits/stdc++.h>

using namespace std;

const int limit = 20e5+10;

long long sum, 
    nums[limit];

int t,
    n,
    m,
    p,
    friends[limit];

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf( "%d",&t);
    
    while(t--){
        
        sum = 0;

        cin>>n>>m;

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        for(int j=0;j<m;j++){
            cin>>friends[j];
        }

        sort(nums,nums+n);
        reverse(nums,nums+n);
        sort(friends,friends+m);

        for(int i=0;i<m;i++){
            if(friends[i]==1){
                sum+=nums[i];    
            }
            sum+=nums[i];
        }
        p = m-1;
        for(int j=0;j<m;j++){
            if(friends[j]==1){
                continue;
            }
            p+=friends[j]-1;
            sum+=nums[p];
        }

        cout<<sum<<endl;
    }

    return 0;
}