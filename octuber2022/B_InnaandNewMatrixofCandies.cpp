#include<bits/stdc++.h>

using namespace std;

int n,
    m,
    cont,
    mark[1005];

bool flag = true;

string mat[1005];

int main(){

    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>mat[i];
    }    

    for(int i=0;i<n;i++){
        bool enano=false;
        int num=0;
        for(int j=0;j<m;j++){
            if(mat[i][j]=='S'){
                
                if(!enano){
                    flag = false;
                }
                else{
                    int aux=j-num;
                    if(mark[aux]==0){
                        mark[aux]=1;
                        cont++;
                    }    
                    //cout<<j-num-1<<" "<<mayor<<endl;
                }

                break;
            }
            else if(mat[i][j]=='G'){
                num=j;
                enano=true;
            }

        }
        if(!flag)break;
    }

    //mayor=1000;
    printf("%d\n",(flag)?cont:-1);
    return 0;
}