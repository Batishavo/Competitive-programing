#include<bits/stdc++.h>

using namespace std;

string in,
       out;

void dfs(string a,string b,string s,string path,int n){

    if(n==in.size()*2){
        if(b==out){
            cout<<path[0];
            for(int i=1;i<path.size();i++){
                cout<<" "<<path[i];
            }
            cout<<endl;
        }
        return;
    }

    //push
    if(a.size()>0){
        string aux= a.substr(1,a.size()-1);
        dfs(aux,b,s+a[0],path+'i',n+1);
    }
    //pop
    if(s.size()>0 && s[s.size()-1]==out[b.size()]){
        string aux= s.substr(0,s.size()-1);
        dfs(a,b+s[s.size()-1],aux,path+'o',n+1);
    }
}


int main(){

    while(cin>>in>>out){

        printf("[\n");

        if(in.size()==out.size()){

            dfs(in,"","","",0);
        }

        printf("]\n");

    }

    return 0;
}
