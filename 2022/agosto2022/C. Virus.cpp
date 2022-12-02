#include<bits/stdc++.h>

using namespace std;

const int limit = 10e5+10;

int t,
    n,
    m,
    cont,
    arr[limit],
    sum[limit];

void survirved(){

    sum[0]=n-arr[m-1]+arr[0]-1;

    for(int i=1;i<m;i++){

        sum[i]=arr[i]-arr[i-1]-1;

    }
}

int total_lives(){

    int total= 0,
        acum = 0;

    for(int i=m-1;i>=0;i--){

        if(sum[i]-acum<=0){

            break;
        }
        else if(sum[i]-acum==1){
            total++;
            break;
        }
        else{
            total+=sum[i]-acum-1;
        }
        acum+=4;

    }
    return total;
}

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&m);

        for(int i=0;i<m;i++){
            scanf("%d",&arr[i]);
        }

        sort(arr,arr+m);
        survirved();
        sort(sum,sum+m);
        cont = total_lives();

        printf("%d\n",n-cont);

    }

    return 0;
}
