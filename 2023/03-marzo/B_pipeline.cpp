#include<bits/stdc++.h>

using namespace std;

long long k,
    n,
    total;

long long sumatori(long long num){
    return (num*(num+1))/2;
}

long long binary_search(){
    
    int ini=0,
        fin=k;

    while(ini<fin){

        int mid=(ini+fin)/2+1;
        long long sum_mid=sumatori(mid-1);
        if(total-sum_mid<n){
            fin=mid-1;
        }
        else{
            ini=mid;
        }
        // printf("mid: %d sum: %lld  total: %lld t-m: %lld\n",
        //     mid,sum_mid,total,total-sum_mid
        // );
    }
    return k-ini;
}

int main(){

    cin>>n>>k;
    
    total=sumatori(k-1)+1;

    if(n>total){
        cout<<"-1"<<endl;
    }
    else{
        cout<<binary_search()<<endl;
    }

    return 0;
}