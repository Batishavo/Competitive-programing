#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[1000099];
int main(){
    scanf("%d",&n);
    int impar=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        int aux;
        scanf("%d",&aux);
        sum+=aux;
        if(aux%2!=0){
            arr[impar++]=aux;
        }
    }
    if(impar==0){
        printf("%d\n",0);
    }
    else{
        if(impar%2==0){
            sort(arr,arr+impar);
            /*for(int j=0;j<impar;j++){
                printf("%d ",arr[j]);
            }*/
            printf("%lld\n",sum-arr[0]);
        }
        else{
            printf("%lld\n",sum);
        }
    }
    return 0;
}
