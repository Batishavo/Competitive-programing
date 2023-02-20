#include<bits/stdc++.h>

using namespace std;

const int limit = 10e5+10;

int n,
    arr[limit],
    tmp[limit],
    cont;

int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        tmp[i]=arr[i]/2;
        cont+=arr[i]/2;
    }

    for(int i=0;i<n;i++){
        if(cont==0){
            break;
        }
        else if(abs(arr[i]%2)==1){
            if(cont<0 && arr[i]>0){
                cont++;
                tmp[i]++;
            }
            else if(cont>0 && arr[i]<0){
                cont--;
                tmp[i]--;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<tmp[i]<<endl;
    }

    return 0;
}