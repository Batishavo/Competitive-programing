#include<bits/stdc++.h>

using namespace std;

long long a,b,c,d,t;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);

        if(a*d==c*b){
            printf("0\n");
        }
        else if(a==0 || c==0){
            printf("1\n");
        }
        else{

            //long long dif=abs((a*d)-(c*b));

            //printf("**%lld %lld %lld\n",dif,(a*2)*d,c*b);

            if(( (a*d)%(c*b) == 0 ) ||( (c*b)%(a*d) == 0  )){

                printf("1\n");

            }
            else{
                 printf("2\n");
            }


        }

    }

    return 0;
}
