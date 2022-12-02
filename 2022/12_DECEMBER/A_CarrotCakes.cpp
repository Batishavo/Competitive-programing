#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,t,k,d,total;
    cin >> n >> t >> k >> d ;

    if(n%k==0){
        total=n/k;
    }
    else{
        total=n/k+1;
    }
    total*=t;
    //printf("%d %d \n",total , d+t);
    if(d+t<total){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}