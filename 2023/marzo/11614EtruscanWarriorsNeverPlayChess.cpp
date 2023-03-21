#include <bits/stdc++.h>

using namespace std;

int t;

const int long long limit = 10e9;

long long n,
    mul = 2;

long long bynary_search(){
    long long ini=0,
        fin=limit;
    
    while(ini<fin){

        long long mid = (ini+fin)/2+1;

        if(mid*(mid+1)/2>n){
            fin=mid-1;
        }
        else{
            ini=mid;
        }

    }
    return ini;
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    cin>>t;
    while (t--)
    {
        //n = 10e17;
        cin>>n;
        cout<<bynary_search()<<endl;
    }

    return 0;
}