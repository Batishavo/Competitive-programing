#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d",&test);

    while(test--){

        int zeroes, ones;

        scanf("%d %d", &zeroes , &ones);

        char tmp= (zeroes<ones)?'1':'0';

        int total= zeroes + ones;

        for(int i=0;i<total;i++){
            printf("%c",tmp);
            if(tmp == '0' ){

               zeroes--;

               if(ones>0)
                  tmp='1';

            }
            else if(tmp=='1'){

               ones--;

               if(zeroes>0){
                tmp='0';
               }

            }

        }
        printf("\n");

    }

    return 0;
}
