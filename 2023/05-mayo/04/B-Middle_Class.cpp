#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

long long m,
    arr[limit],
    sum;

int n,
    t,
    num;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>n>>m;

        sum = 0;
        num = 0;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }
        
        sort(arr,arr+n);
        //cout<<sum<<" "<<num<<endl;
        while(num<n && sum/(n-num)<m ){
            //cout<<sum<<" "<<num<<endl;
            sum-=arr[num];
            num++;
        }
        cout<<n-num<<endl;
    }

    return 0;
}