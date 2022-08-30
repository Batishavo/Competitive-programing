#include<bits/stdc++.h>

using namespace std;

int n,t;

string cad1,
       cad2;

int main(){

    cin>>t;

    while(t--){

        cin>>n>>cad1>>cad2;

        bool flag =true;

        for(int i=0;i<n;i++){

            if(cad1[i]==cad2[i] ||
              (cad1[i]=='G' && cad2[i]=='B')||
              (cad1[i]=='B' && cad2[i]=='G')
               ){

              continue;

            }
            else{
                flag=false;
                break;
            }


        }

        printf((flag==true)?"YES\n":"NO\n");
    }

    return 0;
}
