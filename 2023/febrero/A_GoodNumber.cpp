#include<bits/stdc++.h>

using namespace std;

int n,
    k,
    mat[15];

string arr[110];

void clean(){
    for(int i=0;i<=9;i++){
        mat[i] = 0;
    }
}

int sum(){

    for(int i=0;i<=k;i++){
        //printf("%d \n",arr[i]);
        if(mat[i]==0){
            //printf("%d **\n",i);
            return 0;
        }
    }
    return 1;
}

int main(){

    cin>>n>>k;
    int num=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<arr[i].size();j++){
            mat[arr[i][j]-'0']=1;
        }
        num+=sum();
        clean();
    }

    cout<<num<<endl;

    return 0;
}