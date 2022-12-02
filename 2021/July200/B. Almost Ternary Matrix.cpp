#include<bits/stdc++.h>

using namespace std;

int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        int n,m;

        scanf("%d %d",&n,&m);

        int ini=1;
        for(int i=0;i<n;i++){

            printf("%d ",ini);

            int num=(ini==1)?0:1;

            if(i%2==0){

                ini=(ini==1)?0:1;

            }



            for(int j=0;j<m-2;j+=2){

                printf("%d %d ",num,num);

                num=(num==0)?1:0;
            }

            num=(num==0)?0:1;
            printf("%d\n",num);
        }


    }

    return 0;
}
