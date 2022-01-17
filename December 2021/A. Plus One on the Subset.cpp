#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        int n;
        scanf("%d",&n);
        int more=INT_MIN,les=INT_MAX;
        while(n--){
            int aux;
            scanf("%d",&aux);
            if(aux>more){
                more=aux;
            }
            if(aux<les){
                les=aux;
            }
        }
        printf("%d\n",more-les);
    }
    return 0;
}
