#include<bits/stdc++.h>

using namespace std;

long long limit=10e10;

long long n,
    k;

bool posible(long long num){
    long long cont=0;
    for(int i=0;;i++){
        long long aux=num/(pow(k,i));
        cont+=aux;
        if(aux==0 || cont>=n){
            break;
        }
    }
    return cont>=n;
}

long long binary_search(){
    long long ini=0,
        fin=limit;
    
    while(ini<fin){
        long long mid=ini+(fin-ini)/2;
        if(posible(mid)){
            fin=mid;
        }
        else{
            ini=mid+1;
        }
        //7 cout<<mid<<endl;
        //system("pause");
        //cin.get();
    }
    return ini;
}

int main(){

    cin>>n>>k;
    
    cout<<binary_search()<<endl;

    return 0;
}