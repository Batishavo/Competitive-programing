#include<bits/stdc++.h>
using namespace std;

int n,
    m,
    cont,
    arr[105],
    mat[105][105];

queue<int> use;

void desmark(int i){

    for(int j=1;j<=n;j++){
        if(mat[i][j]!=0){
             mat[i][j]=0;
             mat[j][i]=0;
             use.push(j);
        }

    }

}

void solve(){

    bool flag= true;

    while(flag){
        bool aux = false;
        for(int i = 1;i<=n;i++){
            if(arr[i]==1){
                ///printf("%d\n",i);
                arr[i]=0;
                desmark(i);
                aux=true;
            }
        }
        flag = aux;
        if(aux){
            cont++;
            while(!use.empty()){
                int tmp = use.front();
                arr[tmp]--;
                use.pop();
            }
        }
    }
}

int main(){

    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++){

        int aux1,aux2;
        scanf("%d %d",&aux1,&aux2);
        arr[aux1]++;
        arr[aux2]++;
        mat[aux1][aux2]=1;
        mat[aux2][aux1]=1;
    }

    solve();

    printf("%d\n",cont);

    return 0;
}
