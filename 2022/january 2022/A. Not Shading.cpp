#include<bits/stdc++.h>
using namespace std;
char arr[150][150];
bool searchx(int r,int c,int n,int m){
    for(int i=r-1;i<n;i++){
        if(arr[i][c-1]=='B'){
            //printf("a");
            return true;
        }
    }
     for(int i=r-1;i>=0;i--){
        if(arr[i][c-1]=='B'){
            //printf("b");
            return true;
        }
    }
    for(int j=c-1;j<m;j++){
        if(arr[r-1][j]=='B'){
            //printf("c");
            return true;
        }
    }
    for(int j=c-1;j>=0;j--){
        if(arr[r-1][j]=='B'){
           //printf("d");
            return true;
        }
    }
    return false;

}
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        int n,m,c,r;
        scanf("%d %d %d %d",&n,&m,&r,&c);
        int can=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c", &arr[i][j]);
                if(arr[i][j]=='B'){
                    can=1;
                }
            }
        }
       // printf("$%d ",can);
        if(can){
            if(arr[r-1][c-1]=='B'){
                printf("~~0\n");
            }
            else if(searchx(r,c,n,m)){
                printf("~~1\n");
            }
            else{
                printf("~~2\n");
            }
        }
        else{
            printf("~~-1\n");
        }
    }
    return 0;
}
