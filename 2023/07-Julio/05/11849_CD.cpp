#include<bits/stdc++.h>

using namespace std;

int main(){

    int n
        ,m
        ,total=0;
    
    set<int>memo;

    while (scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0){
            break;
        }

        for(int i=0;i<n;i++){
            int aux;
            scanf("%d",&aux);
            memo.insert(aux);
        }

        for(int i=0;i<m;i++){
            int aux;
            scanf("%d",&aux);
            if((memo.find(aux)!=memo.end())){
                total++;
            }

        }

        printf("%d\n",total);

        total=0;
        memo.clear();
    }
    

    return 0;
}