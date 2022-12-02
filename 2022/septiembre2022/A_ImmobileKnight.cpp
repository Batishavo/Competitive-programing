#include<bits/stdc++.h>

using namespace std;
int t,n,m;
int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>n>>m;
        int ax1=(n%2==0 )?0:1,
            ax2=(m%2==0 )?0:1;

        cout<<(n/2)+ax1<<" "<<(m/2)+ax2<<endl;
    
    }

    return 0;
}