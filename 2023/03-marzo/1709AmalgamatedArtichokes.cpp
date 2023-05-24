#include<bits/stdc++.h>

using namespace std;

int p,
    a,
    b,
    d,
    c,
    n;

double price(int k){
    return p*(sin(a*k+b)+cos(c*k+d)+2);
}

int main(){

    while(cin>>p>>a>>b>>c>>d>>n){
        double mayor=price(1),
            answered=0;
        for(int i=2;i<=n;i++){
            double aux=price(i);
            if(aux>mayor){
                mayor=aux;
            }
            else{
                double tmp=mayor-aux;
                answered=max(answered,tmp);
            }
        }
        printf("%.9lf\n",answered);
    }
    

    return 0;
}