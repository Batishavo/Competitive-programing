#include<bits/stdc++.h>
int num [105];
int numN[105];
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        int n;
        int cont=0;
        scanf("%d",&n);
        while(n--){
            int aux;
            scanf("%d",&aux);
            if(aux<0){
                aux=-aux;
                if(numN[aux]==0 && aux!=0){
                    cont++;
                    numN[aux]=1;
                }
                else if(num[aux]==0){
                    cont++;
                    num[aux]=1;
                }
            }
            else{
                if(num[aux]==0){
                    cont++;
                    num[aux]=1;
                }
                else if(numN[aux]==0 && aux!=0){
                    cont++;
                    numN[aux]=1;
                }
            }
        }
        for(int i=0;i<=100;i++){
            num [i]=0;
            numN[i]=0;
        }
        printf("%d\n",cont);
    }
    return 0;
}
