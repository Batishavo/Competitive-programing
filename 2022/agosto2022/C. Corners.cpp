#include<bits/stdc++.h>

using namespace std;

int t,n,m,
    cont_0,cont_1,
    arr_i[]={1,0,-1, 0},
    arr_j[]={0,1, 0,-1};

string mat[510];

bool flag;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&m);

        for(int i=0;i<n;i++){

            cin>>mat[i];

        }

        cont_0=0;
        cont_1=0;
        flag=false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(mat[i][j]=='1'){
                    cont_1++;

                    if(i-1>=0 && j+1<m && mat[i-1][j]=='0' && mat[i][j+1]=='0'){
                        flag=true;
                    }
                    if(i+1<n && j-1>=0 && mat[i+1][j]=='0' && mat[i][j-1]=='0'){
                        flag=true;
                    }
                    if(i-1>=0 && j-1>=0 && mat[i-1][j]=='0' && mat[i][j-1]=='0'){
                        flag=true;
                    }
                    if(i+1<n && j+1<m  && mat[i+1][j]=='0' && mat[i][j+1]=='0'){
                        flag=true;
                    }

                }
                else{
                    cont_0++;

                    for(int k=0;k<4;k++){
                        if(i+arr_i[k]<n && i+arr_i[k]>=0 &&
                           j+arr_j[k]<m && j+arr_j[k]>=0){

                           if(mat[i+arr_i[k]][j+arr_j[k]]=='0'){
                                flag=true;
                           }


                        }
                    }

                }
            }
        }
       // printf("+++");
        if(flag){
            printf("%d\n",cont_1);
        }
        else if(cont_0>0){
                printf("%d\n",cont_1-1);
        }
        else{
           printf("%d\n",cont_1-2);
        }


    }

    return 0;
}
