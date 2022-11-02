#include<bits/stdc++.h>

using namespace std;

int n,m,arr[110][10],cont;

int main(){

    cin>>n>>m;

    for(int i=0;i<m;i++){
        int owes , person , rubles;

        cin>>owes>>person>>rubles;

        arr[owes][1]+=rubles;
        arr[person][0]+=rubles;
    }
    //cout<<"-------------"<<endl;
    for(int i=1;i<=n;i++){
       // printf("%d %d %d\n",i,arr[i][0],arr[i][1]);
        if(arr[i][0]-arr[i][1]>0){
            cont+=arr[i][0]-arr[i][1];
        }
    }

    cout<<cont<<endl;

    return 0;
}