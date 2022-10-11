#include<bits/stdc++.h>

using namespace std;

int t,n1,n2;
string cad1,cad2;

int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin >> cad1 >> cad2;
        n1=cad1.size()-1;
        n2=cad2.size()-1;
        if(cad1 == cad2){
            cout<<"="<<endl;
        }
        else if(cad1[n1] == cad2[n2]){
            if(n1>n2 ){
                if(cad1[n1]=='L')
                    cout<<">"<<endl;
                else 
                    cout<<"<"<<endl;
            }
            else{
                if(cad1[n1]=='S')
                    cout<<">"<<endl;
                else 
                    cout<<"<"<<endl;
            }
        }
        else if((cad1[n1]=='S' && cad2[n2]=='M') ||
                (cad1[n1]=='S' && cad2[n2]=='L') ||
                (cad1[n1]=='M' && cad2[n2]=='L')
        )
        {
            cout<<"<"<<endl;
        }
         else if((cad1[n1]=='L' && cad2[n2]=='S') ||
                 (cad1[n1]=='L' && cad2[n2]=='M') ||
                 (cad1[n1]=='M' && cad2[n2]=='S')
        )
        {
            cout<<">"<<endl;
        }
    
    }
    

    return 0;
}