#include<bits/stdc++.h>

using namespace std;

int t;

string mat[10];

bool lastR(){

    for(int i=0;i<8;i++){
        bool flag = true;
        if(mat[i][0]!='R'){
            continue;
        }
        for(int j=0;j<8;j++){
            if(mat[i][j]!='R'){
                flag = false;
                break;
            }
        }
        if(flag){
            //cout<<i<<endl;
            return true;
        }
    }
    
    return false;
}

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        for(int i=0; i<8; i++){
            cin>>mat[i];
        }

        //cout<<"--";
        
        if(lastR()){
            cout<<"R\n";
        }
        else{
            cout<<"B\n";
        }

    }
    

    return 0;
}