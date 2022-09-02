#include<bits/stdc++.h>

using namespace std;

int n,k,r,c,t;

char mat[505][505];

void mark(){


    for(int i=1;i<=n;i+=k){
        for(int j=1;j<=n;j+=k){
            int cont=j;
            if(i+k>c && i<=c && j+k>t && j<=t){

                //printf("---------------");
                marSpecia(i,j);
                continue;
            }
            for(int x=i;x<i+k;x++){
                mat[x][cont]='X';
                cont++;
            }
            /*for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cout<<mat[i][j];
                }
                cout<<endl;
            */

        }
    }

}

bool revisar(int i,int fi,int j,int fj){

    for(int x=i;x<=fi;x++){
        if(mat[x][j]=='X'){
            return false;
        }
    }
    for(int x=i;x<=fi;x--){
        if(mat[x][j]=='X'){
            return false;
        }
    }
    for(int x=j;x<=fj;x++){
        if(mat[i][x]=='X'){
            return false;
        }
    }
    for(int x=i;x<=fi;x++){
        if(mat[x][j]=='X'){
            return false;
        }
    }

}

void marSpecia(int i,int j){

    int fi=i+k,
        fj=j+k;

    for(i;i<=i+k;i++){
        for(j;j<=j+k;j++){

            if(revisar(i,fi,j, fj)){
                mat[i][j]='X'
            }
        }

}

void clean(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mat[i][j]='.';
        }
    }

}

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d %d %d",&n,&k,&c,&t);

        mat[r][c]='X';
        clean();
        mark();
        cout<<"---"<<endl;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<mat[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}

