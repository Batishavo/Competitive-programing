#include<bits/stdc++.h>
using namespace std;
int v[50];
int F(int n){
    if(v[n]!=0){
        return v[n];
    }
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    v[n]=F(n-1)+F(n-2);
    return v[n];
}
int main(){
    printf("%d",F(7));
    return 0;
}
