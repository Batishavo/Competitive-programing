#include<bits/stdc++.h>

using namespace std;

string arr[150];

int mat[150][150];
int main(){

    int test;
    scanf("%d",&test);

    while(test--){
        int n;
        int total=0;
        char tp='a';
        scanf("%d",&n);
        for(int i=0;i<n;i++){

            cin>>arr[i];

            /*for(int j=0;j<n;j++){

                scanf("%d",&arr[i][j]);
            }*/
        }

        for(int i=0;i<(n+1)/2;i++){
            for(int j=0;j<n/2;j++){
                 /*int num= arr[i][j]+
                     arr[i][n-j-1]+
                     arr[n-i-1][j]+
                     arr[n-i-1][n-j-1];*/

                 int num =  arr[i][j]+
                            arr[j][n-i-1]+
                            arr[n-i-1][n-j-1]+
                            arr[n-j-1][i];
                    /* mat[i][j]=tp;
                     mat[i][n-j-1]=tp;
                     mat[n-i-1][j]=tp;
                     mat[n-i-1][n-j-1]=tp;
                     tp++;*/

                num-='0'*4;

                if(num==3 || num==1){
                    total++;
                }
                if(num==2){
                    total+=2;
                }

            }
        }

        printf("%d\n",total);
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c ",mat[i][j]%10);
            }
            printf("\n");
        }*/

    }

    return 0;
}
