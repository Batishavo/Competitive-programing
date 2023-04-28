#include<bits/stdc++.h>

using namespace std;

const int limit = 10e4+10;

int m,
    n,
    arr[limit];

bool comp(int a,int b){
    a=abs(a);
    b=abs(b);
    if(a%m==b%m){
        if(a%2!=b%2){
            return a%2==1;
        }
        else{
            if(a%2==1){
                return a>b;
            }
            else{
                return a<b;
            }
        }
    }
    return a%m<b%m;
}

int main(){
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    while(cin>>n>>m){
        if(n==0 && m==0){
            break;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n,comp);
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<endl;
        }
    }
    cout<<"0 0"<<endl;

    return 0;
}