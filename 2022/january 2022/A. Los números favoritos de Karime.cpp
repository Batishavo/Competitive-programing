#include<bits/stdc++.h>
using namespace std;
int combination[1005];
int favorite[105];
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&combination[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&favorite[i]);
    }
    for(int i=0;i<m;i++){
        int s[5]={0,0,0,INT_MAX,0};
        //printf("%)
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                int sum=combination[j]+combination[k];
                int menor=abs(sum-favorite[i]);
                if(menor<s[3]){
                    s[0]=j+1;
                    s[1]=k+1;
                    s[2]=sum;
                    s[3]=menor;
                }
            }
        }
        for(int j=0;j<3;j++){
            printf("%d ",s[j]);
        }

        printf("\n");
    }
    return 0;
}
