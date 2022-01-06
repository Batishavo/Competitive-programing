#include<bits/stdc++.h>
using namespace std;
struct disjoint{
    int l;
    int r;
};
disjoint intervalos[1005];
int memo[1005];
int use[1005];
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            cin>>intervalos[i].l;
            cin>>intervalos[i].r;
            for(int j=intervalos[i].l;j<=intervalos[i].r;j++){
                memo[j]++;
            }
        }
        for(int i=0;i<n;i++){
            int menor=INT_MAX;
            int valor=0;
            for(int j=intervalos[i].l;j<=intervalos[i].r;j++){
                if(memo[j]<menor && use[j]==0){
                    menor=memo[j];
                    valor=j;
                }
                memo[j]--;
            }
            use[valor]=1;
            printf("%d %d %d\n",intervalos[i].l,intervalos[i].r,valor);
        }
        for(int i=1;i<=n;i++){
            use[i]=0;
        }

    }
    return 0;
}
