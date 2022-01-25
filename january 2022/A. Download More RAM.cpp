#include<bits/stdc++.h>
using namespace std;
struct ram{
    int price;
    int value;
};
bool orden(ram a,ram b){
    return a.price<b.price;
}
ram my_data[110];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d",&my_data[i].price);
        }
        for(int i=0;i<n;i++){
             scanf("%d",&my_data[i].value);
        }
        sort(my_data,my_data+n,orden);
        /*for(int i=0;i<n;i++){
            printf("%d ",data[i].price);
        }
        printf("\n");
        for(int i=0;i<n;i++){
            printf("%d ",data[i].value);
        }
        printf("\n");*/
        for(int i=0;i<n;i++){
            if(my_data[i].price<=k){
                k+=my_data[i].value;
            }
            else{
                break;
            }
        }
        printf("%d\n",k);
    }
    return 0;
}
