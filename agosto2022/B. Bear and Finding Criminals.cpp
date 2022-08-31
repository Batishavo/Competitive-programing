#include<bits/stdc++.h>

using namespace std;

int n,m,
    arr[110];

int main(){

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){

        scanf("%d",&arr[i]);
    }

    int p1=m-1,p2=m+1,cont=arr[m];

    while(p1>=1 || p2<=n){

        if((p1<1 && arr[p2]==1)||
           (arr[p1]==1 && p2>n))
        {
            cont++;
        }
        else if(arr[p1]==1 && arr[p2]==1){
            cont+=2;
        }
        p1--;
        p2++;

    }

    printf("%d\n",cont);

    return 0;
}
