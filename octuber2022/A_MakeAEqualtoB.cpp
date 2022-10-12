#include<bits/stdc++.h>

using namespace std;

int t,
    n,
    c1,
    c2,
    cont,
    arr1[200],
    arr2[200];

int main(){

    scanf( "%d",&t);
    
    while(t--){
        c1=0;
        c2=0;
        cont=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr1[i];
            c1+=arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
            c2+=arr2[i];
        }

        for(int i=0;i<n;i++){
            if(arr1[i]!=arr2[i]){
                if(c1==c2){
                    cont++;
                    break;
                }
                else{
                    cont++;
                    if(c1<c2){
                        c2--;
                    }
                    else{
                        c1--;
                    }
                }
            }
        }

        cout<<cont<<endl;

    }

    return 0;
}