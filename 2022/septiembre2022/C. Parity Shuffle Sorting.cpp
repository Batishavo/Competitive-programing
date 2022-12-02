#include<bits/stdc++.h>

using namespace std;

const int limit=(10e5)+10;

int t,n,
    arr[limit];

vector<pair<int,int>>operation;

int calcular(int i,int j){

    if((i+j)%2==1){
        return i;
    }
    return j;
}

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        if(n==1){
            printf("0\n");
            continue;
        }
        int tmp=calcular(arr[1],arr[n]);

        arr[1]=tmp;
        arr[n]=tmp;

        operation.push_back({1,n});


        for(int i=2;i<=n-1;i++){

            if(arr[i]==tmp)continue;

            int aux1=calcular(arr[i],tmp),
                aux2=calcular(tmp,arr[i]);

            if(aux1==tmp){
                operation.push_back({i,n});
                arr[i]=aux1;
            }
            else if(aux2==tmp){
                operation.push_back({1,i});
                arr[i]=aux2;
            }

        }
       /* cout<<"--";
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }*/
        printf("%d\n",operation.size());
        for(auto x:operation){
            printf("%d %d\n",x.first,x.second);
        }
        operation.clear();
    }


    return 0;
}
