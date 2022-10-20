#include<bits/stdc++.h>

using namespace std;

const int limit = 2*10e5+10;

int t,n;

long long aux,
          bless[limit],
          sum;

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>n;
    
        for(int i=0;i<n;i++){

            cin>>aux;
            sum+=aux;

        }

        for(int i=0;i<n;i++){
            cin>>bless[i];
        }

        int ini=0,
            end=n-1;
        
        while(ini<end){

            if(bless[ini]<bless[end]){
                sum+=bless[ini];
                ini++;
            }
            else{
                sum+=bless[end];
                end--;
            }
        }
       // cout<<"--";
        cout<<sum<<endl;
        sum =0;

    }

    return 0;
}