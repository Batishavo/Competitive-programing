#include<bits/stdc++.h>
using namespace std;
int bynary_search(int a, int b){
    int total=(a+b)/4,ini=0;
    int les=min(a,b);
    while(total>les){
        int mid=(ini+total)/2;
        if(mid>=les){
            total=mid;
        }
        else{
            ini=mid+1;
        }
        //printf("ini:%d total:%d mid:%d\n",ini,total,mid);

    }
    return total;
}
int main(){
    int query;
    scanf("%d",&query);
    while(query--){
        int a,b;
        scanf("%d %d",&a,&b);
        int solution=bynary_search(a,b);
        printf("%d\n",solution);


    }
    return 0;
}
