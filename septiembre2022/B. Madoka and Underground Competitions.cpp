#include<bits/stdc++.h>

using namespace std;

int n,k,r,c,t;

char mat[505][505];

int pi[5]={0,0,0,0},
    pj[5]={0,0,0,0};

queue<pair<int,int>>marcas;
pair<int,int>actual;

void clean(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mat[i][j]='.';
        }
    }

}
bool putDot(int i,int j){

    for(int x=i+1;x<i+k;x++){
        if(x>n){
            break;
        }
        if(mat[x][j]=='X'){
            return false;
        }
    }
    for(int x=i-1;x>i-k;x--){
        if(x<1){
            break;
        }
        if(mat[x][j]=='X'){
            return false;
        }
    }
    for(int x=j+1;x<j+k;x++){
        if(x>n){
            break;
        }
        if(mat[i][x]=='X'){
            return false;
        }
    }
    for(int x=j-1;x>j-k;x--){
        if(x<1){
            break;
        }
        if(mat[i][x]=='X'){
            return false;
        }
    }
    return true;
}

void bfs(){

    while(!marcas.empty()){
        actual=marcas.front();
        marcas.pop();
        int i=actual.first,
            j=actual.second;
        mat[i][j]='X';
        //putDot(i,j);
        for(int k=0;k<4;k++){

            if(i+pi[k]>=1 &&  i+pi[k]<=n && j+pj[k]>=1 && j+pj[k]<=n){
                if(mat[i+pi[k]][j+pj[k]]=='.'){
                   marcas.push(make_pair(i+pi[k],j+pj[k]));
                }
            }

        }


    }


}

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d %d %d",&n,&k,&r,&c);
        if(k==1){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cout<<'X';
                }
            cout<<endl;
            }
            continue;
        }
        clean();
        pi[0]=k;pi[2]=-k;
        pj[1]=k;pj[3]=-k;
        marcas.push(make_pair(r,c));
        bfs();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mat[i][j]=='.' &&  putDot(i,j)){
                    marcas.push(make_pair(i,j));
                    bfs();
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<mat[i][j];
            }
            cout<<endl;
        }
       // printf("t:%d\n",t);
    }
    return 0;
}
