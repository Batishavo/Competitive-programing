#include<bits/stdc++.h>

using namespace std;

const int limit = (2*10e5)+10;

int arr[limit];

void clean(int tasks){

    for(int i=1;i<=tasks;i++){
        arr[i]=0;
    }

}
bool can(int num, int tasks,int workers){

    long long dTime = 0,
              ftime = 0;

    for(int i=1 ;i <= workers; i++){

        long long tmp = arr[i]-num;

        if(tmp<0){
            ftime+=(abs(tmp))/2;
        }
        else{
            dTime+=tmp;
        }
    }


    return ftime>=dTime;

}
int bynary(int n, int tasks){

    int ini = 1,
        fin = tasks*2;

    while(ini<fin){

        int mid=((ini+fin)/2);

        bool posible=can(mid,tasks,n);

        if(posible){

            fin=mid;
        }
        else{
            ini=mid+1;
        }

    }
    return fin;

}
int main(){

    int test;
    scanf("%d",&test);

    while(test--){

        int employes,tasks;

        scanf("%d %d",&employes,&tasks);

        for(int i=1;i<=tasks;i++){

            int aux;
            scanf("%d",&aux);
            arr[aux]++;
        }

        int hours=bynary(employes,tasks);

        printf("%d\n",hours);

        clean(tasks);
    }

    return 0;
}
