#include<bits/stdc++.h>
using namespace std;
struct cordenada{
    int i;
    int j;
};
int mat[200][200];
int di[5]={1,0,-1,0};
int dj[5]={0,1,0,-1};
int main(){
    queue<cordenada> q;
    int test;
    scanf("%d",&test);
    for(int k=1;k<=test;k++){

        int n,m;
        scanf("%d %d",&n,&m);
        //printf("------------\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&mat[i][j]);

            }
        }
    }
    return 0;
}
