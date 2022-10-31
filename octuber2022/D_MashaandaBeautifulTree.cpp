#include<bits/stdc++.h>

using namespace std;
const int limit = 262154;

int t,n,arr[limit],cont;

bool flag;

void solve(int ini,int fin){
    if(ini == fin){
        return;
    }
    int menor=INT_MAX,mayor=INT_MIN;
    for(int i=ini;i<=fin;i++){
        menor=min(menor,arr[i]);
        mayor=max(mayor,arr[i]);
    }
    int comp=menor+(mayor-menor)/2;
    //printf("ini: %d fin: %d\n",ini,fin);
    int mid= ini+(fin-ini)/2;
    //printf("mid: %d p: %d comp: %d \n",mid,arr[mid],comp);
    if(arr[mid]>comp){
        cont++;
        for(int i=ini;i<=mid;i++){
            if(arr[i]<=comp){
                flag = false;
                //cout<<"X1"<<endl;
                return;
            }
        }
        for(int i=mid+1;i<=fin;i++){
            if(arr[i]>comp){
                flag = false;
                //cout<<"X2"<<endl;
                return;
            }
        }
        solve(ini,mid);
        solve(mid+1,fin);
        
    }
    else{
        for(int i=ini;i<=mid;i++){
            if(arr[i]>comp){
                flag = false;
                //cout<<"Y1"<<endl;
                return;
            }
        }
        for(int i=mid+1;i<=fin;i++){
            if(arr[i]<=comp){
                flag = false;
                //cout<<"Y2"<<endl;
                return;
            }
        }
        solve(ini,mid);
        solve(mid+1,fin);
    }
    

}

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin >>n;

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        flag=true;
        cont=0;
        solve(1,n);
        //cout<<"**";
        if(flag){

            cout<<cont<<endl;

        }
        else{
            cout<<-1<<endl;
        }

    }

    return 0;
}