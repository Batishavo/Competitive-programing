#include<bits/stdc++.h>
using namespace std;
int  main(){
    int n,x;
    scanf("%d %d",&x,&n);
    int total=x;
    for(int i=0;i<n;i++){
        total+=x;
        int auz;
        scanf("%d",&auz);
        total-=auz;
    }
    printf("%d\n",total);
    return 0;
}
