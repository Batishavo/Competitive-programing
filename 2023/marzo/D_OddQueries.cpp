#include<bits/stdc++.h>

using namespace std;

const int limit= 20e5+10;

int t,
    n,
    m,
    l,
    r,
    k;

long long sum,
    aux,
    arr[limit];

long long total(){
    long long p1=0,
        p2=k*(r-l+1),
        p3=0;

    if(l!=1){
        p1=arr[l-1];
    }

    if(r!=n){
        //cout<<arr[n]<<" "<<arr[l]<<endl;
        p3=arr[n]-arr[r];
    }
    //printf("p1: %lld P2: %lld p3: %lld sum: %lld\n", p1, p2, p3,p1+p2+p3);
    return p1+p2+p3;
}

int main(){

    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);

    scanf( "%d",&t);
    
    while(t--){
        
        cin>>n>>m;
        sum=0;
        for(int i=1; i<=n; i++){
            cin>>aux;
            sum+=aux;
            arr[i]=sum;
        }
        for(int i=0;i<m;i++){
            cin>>l>>r>>k;
            if(total()%2==0){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
        
    
    }

    return 0;
}