#include<bits/stdc++.h>

using namespace std;

const int limit = 200;

int t,
    n,
    cont,
    arr[limit];

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin >> n;

        cont=0;

        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for(int i=1;i<n;i++){
            if(arr[i]%2==arr[i-1]%2){
                cont++;
            }
        }
        // cout<<"--";
        cout<<cont<<endl;
    }
    

    return 0;
}