#include<bits/stdc++.h>

using namespace std;

int t,n,arr[110],tmp[110];

bool posible(int mid){

    int p2=mid;
    if(mid==0){
        return true;
    }
    
    for(int i=0;i<mid;i++){
        tmp[i]=arr[i];
    }

    for(int i=mid-1;i>=0;i--){

    }
    return true;
}

int binary(){

    int ini=0,fin=n;

    while(ini<fin){
        int mid=(ini+fin)/2+1;

        if(posible(mid)){
            ini=mid;
        }
        else{
            fin=mid-1;
        }

    }
    return ini;
}

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>n;
        for(int i=0;i<n;i++){

            cin>>arr[i];

        }

        sort(arr,arr+n);

        cout<<binary()<<endl;
    
    }

    return 0;
}