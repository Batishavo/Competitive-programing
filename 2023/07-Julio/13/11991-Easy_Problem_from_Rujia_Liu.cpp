#include<bits/stdc++.h>

using namespace std;

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n
        ,m;

    map<int,vector<int>>my_nums;

    while(scanf("%d %d",&n,&m)!=EOF){
        
        my_nums.clear();
        
        for(int i=0;i<n;i++){
            
            int aux;
    
            scanf("%d",&aux);
            my_nums[aux].push_back(i);

        }

        for(int i=0;i<m;i++){
            
            int aux
                ,aux2;
            
            scanf("%d %d",&aux,&aux2);

            if(aux > my_nums[aux2].size()){
                printf("0");
            }
            else{
                printf("%d",my_nums[aux2][aux-1]+1);
            }
            printf("\n");
        }
    }

    return 0;
}