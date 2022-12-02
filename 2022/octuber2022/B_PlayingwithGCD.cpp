#include<bits/stdc++.h>

using namespace std;

const int limit = 10e5+10;

int t,
    n;

bool flag;

long long lcm(long long x, long long y){
    long long g= __gcd(x,y);
    return (x*y/g);
}

int main(){

    scanf( "%d",&t);
    
    while(t--){
        
        flag=true;

        cin>>n;
        
        vector<long long>arr(n+10,1),
                         arr2(n+10,1);

        for(int i=1;i<=n;i++){

            cin>>arr[i];
        }
        arr[0]=1;
        arr2[0]=1;
        
        for(int i=1;i<=n+1;i++){
            arr2[i]=lcm(arr[i],arr[i-1]);
        }
        for(int i=1;i<=n;i++){
            if(__gcd(arr2[i],arr2[i+1])!=arr[i]){
                flag=false;
                break;
            }
        }
        
        // for(int i=0;i<=n;i++){
        //     cout<<arr2[i]<<" ";
        // }
        cout<<endl;
        printf(flag?"YES\n" : "NO\n");
    
    }

    return 0;
}