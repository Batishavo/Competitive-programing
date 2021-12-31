#include<bits/stdc++.h>
using namespace std;
struct cordenada{
    int i;
    int j;
};
int n,m;
int mat[200][200];
int use[200][200];
int di[10]={1,0,-1, 0,1, 1,-1,-1};
int dj[10]={0,1, 0,-1,1,-1, 1,-1};
int bfs(int i, int j){
    queue<cordenada> q;
    cordenada nv;
    nv.i=i;
    nv.j=j;
    q.push(nv);
    use[i][j]=1;
    int cont=0;
    while(!q.empty()){
        cont++;
        cordenada act=q.front();
        q.pop();
        int num=mat[act.i][act.j];
        for(int k=0;k<8;k++){
            int pi=act.i+di[k];
            int pj=act.j+dj[k];
            if(pi>=0 && pi<n && pj>=0 && pj<m && mat[pi][pj]==1){
                if(use[pi][pj]==0){
                    use[pi][pj]=1;
                    cordenada nueva;
                    nueva.i=pi;
                    nueva.j=pj;
                    q.push(nueva);
                }
            }
        }
    }
    return cont;
}
int main(){
    int test;
    scanf("%d",&test);
    for(int k=1;k<=test;k++){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        int resultado=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && use[i][j]==0){
                   int comp=bfs(i,j);
                   resultado=max(resultado,comp);
                }
            }
        }
       // printf("\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               // printf("%d ",use[i][j]);
                use[i][j]=0;
            }
           // printf("\n");
        }
        printf("Case #%d: %d\n",k,resultado);
    }
    return 0;
}
