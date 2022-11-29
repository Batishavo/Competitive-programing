#include<bits/stdc++.h>

using namespace std;

long long n,m,num=10,comp=9,ant,piv=9,pos=1;

int main(){


    cin>>n>>m;
    while(comp<n && m>0){ 
        long long aux=n%num+(num/10)-ant;
       // printf("%lld %lld %lld %lld\n",n,m,aux,ant);
        if(aux<n && n%num<comp){
          //  cout<<"x"<<endl;
            if(aux>m || aux>n){
                break;
            }
            n-=aux;
            m-=aux;
        }
        ant+=piv*pos;
        num*=10;
        comp*=10;
        pos*=10;
        
    }

    cout<<n;
    
    return 0;
}