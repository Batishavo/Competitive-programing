#include<bits/stdc++.h>

using namespace std;

int t,n,mayor;

int arr[2001];

void ver1(){

    for(int i=1;i<n;i++){
        int num=arr[i]-arr[0];
        mayor=max(num,mayor);
    }

}

void ver2(){
    for(int i=n-2;i>=0;i--){
        int num=arr[n-1]-arr[i];
        mayor=max(num,mayor);
    }
}
void ver3(){

    for(int i=1;i<n;i++){

        int pos=i-1,
            num=arr[pos]-arr[i];

        mayor=max(num,mayor);
    }

}
int main(){

    scanf("%d",&t);

    while(t--){

        mayor=INT_MIN;

        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        ver1();
        ver2();
        ver3();
        if(n==1){
            mayor=0;
        }
        printf("%d\n",mayor);

    }


    return 0;
}
