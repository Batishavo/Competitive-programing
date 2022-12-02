#include<bits/stdc++.h>
using namespace std;


map<int,int>menor;
map<int,int>major;
int main(){

    int test;
    scanf("%d",&test);

    while(test--){

        int n,m;

        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            int aux;
            scanf("%d",&aux);
            //printf("--%d %d\n",menor[aux],major[aux]);

                if(menor[aux]==0){
                    menor[aux]=i;
                }
                if(major[aux]<i ){
                    major[aux]=i;
                }


            // printf("--%d %d\n",menor[aux],major[aux]);

        }
        for(int i=0;i<m;i++){
            int aj,bj;
            scanf("%d %d",&aj,&bj);
            if(menor[aj]!=0 && major[bj]!=0){
                if(menor[aj]<major[bj]){
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
            }
            else{
                printf("NO\n");
            }


        }
        menor.clear();
        major.clear();

    }

    return 0;
}
