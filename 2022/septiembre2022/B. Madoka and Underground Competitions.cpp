#include<bits/stdc++.h>

using namespace std;

int n,k,r,c,t;

char mat[505][505];
//int cont=1;
void clean(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mat[i][j]='.';
        }
    }

}

void putX(int i,int j){
    if(i>=1 && i<=n && j>=1 && j<=n){
        mat[i][j]='X';
        //cont++;
    }
}
void mov(int x){
    //cont=1;
    int j=r+1;
    for(int i=x+1;i<n+k;i++){
        putX(j,i);
        j++;
    }
    j=r-1;
    for(int i=x-1;i>1-k;i--){
        putX(j,i);
        j--;
    }
}
void mark(){

    for(int x=c;x<n+n;x+=k){
        putX(r,x);
        //mat[r][x]='O';
        mov(x);
        //break;
    }
    for(int x=c;x>1-n;x-=k){
        //mat[r][x]='O';
        putX(r,x);
        mov(x);
        //break;
    }
}

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d %d %d",&n,&k,&r,&c);
        clean();
        //mat[r][c]='X';
        mark();
        //mat[r][c]='O';
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
