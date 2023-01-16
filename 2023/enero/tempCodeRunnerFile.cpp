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
        int num=0,
            cont=1;
        for(int i=n-1;i>=0;i--){
            arr[i]=k-num;
            if(k-(num+cont+1)>1){
                num+=cont;
                cont++;
            }
            else{
                num++;
            }
        }
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        cout<<endl;
    }

    return 0;
}