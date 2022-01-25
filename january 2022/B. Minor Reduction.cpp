#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        string cad;
        cin>>cad;
        int flag=0;
        for(int i=cad.length()-1;i>=1;i--){
            int num=cad[i]+cad[i-1]-('0'*2);
            if(num>=10){
                cad[i]=(num%10)+'0';
                cad[i-1]='1';
                flag=1;
                break;
            }
        }
        if(flag==0){
            int limit=cad.length();
            cad[1]=cad[0]+cad[1]-('0');
            for(int i=1;i<limit;i++){
                cout<<cad[i];
            }
            cout<<endl;
        }
        else{
            cout<<cad<<endl;

        }
    }
    return 0;
}
