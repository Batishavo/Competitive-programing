#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        long long inital, total;
        scanf("%lld %lld",&inital,&total);
        long long cant=total/4;
        cant++;
        if(total%4==0){
            printf("case 1\n");
            printf("%lld\n",inital);
        }
        else if(total%4==3){
            printf("case 2\n");
            if(inital%2==0){
                printf("%lld\n",inital+(4*cant));
            }
            else{
                printf("%lld\n",inital-(4*cant));
            }
        }
        else if(total%4==2){
            printf("case 3\n");
            if(inital%2==0){
                printf("%lld\n",inital+1);
            }
            else{
                printf("%lld\n",inital-1);
            }
        }
        else{
            printf("case 4\n");
            cant--;
            if(inital%2==0){
                printf("%lld\n",inital-(4*cant)-1);
            }
            else{
                printf("%lld\n",inital+(4*cant)+1);
            }
        }
    }
    return 0;
}
