#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
       int n,m,rb,cb,rd,cd;
       int b=1,d=1;
       scanf("%d%d %d%d %d%d",&n,&m,&rb,&rd,&cb,&cd);
        int cont=0;
        while(rb!=cb && rd!=cd){
            if(rb+b<1 || rb+b>n){
                b=-b;
            }
            if(rd+d<1 || rd+d>m){
                d=-d;
            }
            rb+=b;
            rd+=d;
            cont++;
           // printf("cont:%d rb:%d rd:%d b:%d d:%d\n",cont,rb,rd,b,d);
            //system("pause");
        }
        printf("--%d\n",cont);


    }

    return 0;
}
