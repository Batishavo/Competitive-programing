#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        string cad;
        cin>>cad;
        int cad_size=cad.length();
        if((cad[cad_size-1]-'0')%2==0){
            printf("0\n");
        }
        else if((cad[0]-'0')%2==0){
            printf("1\n");
        }
        else{
            bool flag=0;
            for(int i=0;i<cad_size;i++){
                if((cad[i]-'0')%2==0){
                    printf("2\n");
                    flag=1;
                    break;
                }
            }
            if(!flag){
                printf("-1\n");
            }
        }
    }
    return 0;
}
