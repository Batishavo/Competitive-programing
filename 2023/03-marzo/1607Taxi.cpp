#include<bits/stdc++.h>

using namespace std;

int n,sun_n,m,sum_m;

int main(){

    cin>>n>>sun_n>>m>>sum_m;

    while(n<m){
        if(n+sun_n>m){
            n=m;
            break;
        }
        n+=sun_n;
        m-=sum_m;
    }
    cout<<n<<endl;

    return 0;
}