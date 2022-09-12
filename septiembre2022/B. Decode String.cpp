#include<bits/stdc++.h>

using namespace std;

int t,n;
string cad,result;

char oneCharacter(int i){

    return i+'a'-1;

}

char twoCharacter(int i,int j){

    int num=(i*10)+j;

    return num+'a'-1;

}

int main(){

    cin>>t;

    while(t--){

        cin>>n>>cad;

        result="";

        for(int i=0;i<n;i++){
            if(i+2<n && cad[i+2]=='0'){
                if(i+3<n && cad[i+3]=='0'){
                    result+=oneCharacter(cad[i]-'0');
                }
                else{
                    result+=twoCharacter(cad[i]-'0',cad[i+1]-'0');
                    i+=2;
                }
            }
            else{
                result+=oneCharacter(cad[i]-'0');
            }


        }
        cout<<result<<endl;
    }

    return 0;
}
