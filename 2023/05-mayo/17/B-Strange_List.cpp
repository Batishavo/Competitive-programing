#include<bits/stdc++.h>

using namespace std;

int t,
    n;

vector<pair<long long,long long>> arr;

long long sum = 0,
    x;

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf( "%d",&t);
    
    while(t--){
        
        arr.clear();

        sum = 0;

        scanf("%d %lld",&n,&x);

        for(int i=0; i<n; i++){
            long long aux;
            scanf("%lld",&aux);
            arr.push_back({aux,1});
        }
        
        for(int i=0;i<arr.size();i++){
            if(arr[i].first%x!=0){
                break;
            }
            arr.push_back({arr[i].first/x,x*arr[i].second});
        }

        for(int i=0;i<arr.size();i++){
            //cout<<arr[i].first<<" "<<arr[i].second<<endl;
            sum+=arr[i].first*arr[i].second;
        }

        printf("%lld\n",sum);

    }

    return 0;
}