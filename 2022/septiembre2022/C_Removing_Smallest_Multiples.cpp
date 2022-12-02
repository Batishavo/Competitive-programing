#include<bits/stdc++.h>

using namespace std;

const int limit = (10e6)+10;

int t,n;
string cad;
long long cont;
vector<int> divs;
int main(){
    cin>> t;
    while(t--){
        
        cin>>n>>cad;
        for(int i=0;i<n;i++){
            
            if(cad[i]=='0'){
                bool flag=false;
                for(auto x:divs){
                    if((i+1)%x==0){
                        flag=true;
                        cont+=x;
                        break;
                    }
                }
                if(!flag){
                    cont+=i+1;
                    divs.push_back(i+1);
                }
            }
        }

        cout<<"--"<<cont<<endl;
        cont=0;
        divs.clear();
    }

    return 0;
}