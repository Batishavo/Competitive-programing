#include<bits/stdc++.h>
using namespace std;
int v[51][51];
int P(int i,int j){
    if(j==1 ||i==j){
        return 1;
    }
    if(v[i][j]!=0){
        return v[i][j];
    }
    v[i][j]=P(i-1,j-1)+P(i-1,j);
    return v[i][j];
}
int main(){
    printf("%d",P(5,3));
    return 0;
}
