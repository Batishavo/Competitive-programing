#include<bits/stdc++.h>

using namespace std;

string cad,zeros,ones,twos;
bool flag= true;


int main(){

    cin >> cad;

    for(int i=0;i<cad.size();i++){

        if(cad[i]=='0' && flag){
            zeros+='0';
        }
        else if(cad[i]=='0' && !flag){
            twos+='0';
        }
        else if(cad[i]=='1'){
            ones+='1';
        }
        else{
            twos+='2';
            flag=false;
        }

    }
    cout<<zeros<<ones<<twos<<endl;
    return 0;
}