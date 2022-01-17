#include<bits/stdc++.h>
using namespace std;
int arr[200];
string cads[200];
string binario(long long n,int m){
    string cad="";
    while(n>0){
        if(n%2!=0){
            cad+='1';
        }
        else{
            cad+='0';
        }
        n/=2;
    }
    while(cad.length()<m){
        cad+='0';
    }
    reverse(cad.begin(),cad.end());
    cout<<cad<<endl;
    return cad;
}
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        int m;
        long long n;
        scanf("%lld %d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            cads[i]=binario(arr[i],m);
        }
        long long solution=0,piv=1;
        for(int i=m-1;i>=0;i--){
            int one=0,cero=0;
            for(int j=0;j<n;j++){
                if(cads[j][i]=='0'){
                    cero++;
                }
                else{
                    one++;
                }
            }
            if(one>cero){
                solution+=piv;
            }
            piv*=2;
        }
        printf("~~~~~%d\n",solution);
        /*for(int i=0;i<n;i++){
            cout<<cads[i]<<endl;
        }*/
    }
    return 0;
}
