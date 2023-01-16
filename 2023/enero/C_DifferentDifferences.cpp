#include<bits/stdc++.h>

using namespace std;

int t,
    k,
    n,
    arr[50];

int main(){

    scanf( "%d",&t);
    
    while(t--){
        
        cin>>n>>k;
        int cont=1;
        arr[n]=k;
        for(int i=n-1;i>=1;i--){
            
            if(arr[i+1]-cont>=i){
                arr[i]=arr[i+1]-cont;
                cont++;
            }
            else{
              arr[i]=i;  
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d ",arr[i]);
        }
        cout<<endl;
    }

    return 0;
}