#include<bits/stdc++.h>

using namespace std;

int n,
    m,
    t;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&m);

        if((n==1   &&   m == 1) ||
           (n==m)               ||
           (n%2==0 && m%2==0)   ||
           (n%2==1 && m%2==1)
           ){

            cout<<"Tonya"<<endl;

        }
        else{
            cout<<"Burenka"<<endl;
        }

    }

    return 0;
}
