#include<bits/stdc++.h>

using namespace std;

int step,mod;

int seed(int x){
    if(x == 0 || x ==1){
        return 0;
    }
    return (seed(x-1)+step)%mod;
}

int main(){

    while(scanf("%d %d",&step,&mod)!=EOF){
        // for(int i=1;i<100;i++){
        //     cout<<seed(i)<<endl;
        // }
        printf("%10d%10d    %s\n\n", step, mod, __gcd(step, mod) == 1 ? "Good Choice" : "Bad Choice");
    }

    return 0;
}