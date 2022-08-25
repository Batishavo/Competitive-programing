#include<bits/stdc++.h>

using namespace std;

int n,m;
string c;

int main(){

    cin>>c>>n;
    m=c[0]-('a'-1);
    //printf("%d %d\n",m,n);
    if(n%2==0){

        if(m%2==0){
            cout<<"NEGRO"<<endl;
        }
        else{
            cout<<"BLANCO"<<endl;
        }

    }
    else{
            //cout<<"x"<<endl;
        if(m%2==0){
            cout<<"BLANCO"<<endl;
        }
        else{
            cout<<"NEGRO"<<endl;
        }
    }

    return 0;
}
