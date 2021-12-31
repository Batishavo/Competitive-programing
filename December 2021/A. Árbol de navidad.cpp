#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int sum=1;
    int m=n-1,x=n-2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf(" ");
        }
        for(int j=0;j<sum;j++){
            printf("*");
        }
        printf("\n");
        m--;
        sum+=2;
    }
    for(int i=0;i<x;i++){
        printf(" ");
    }
    printf("###\n");
    for(int i=0;i<x;i++){
        printf(" ");
    }
    printf("###\n");
    return 0;
}
