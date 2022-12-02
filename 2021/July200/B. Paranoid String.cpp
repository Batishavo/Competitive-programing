#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        int n;

        string cad;

        cin>>n>>cad;

        long long ans = cad.length();

        for(int i = 1 ; i < n ; i++){

            if(cad[i]!= cad[i-1]){

                ans+= i;
            }

        }

        cout<<ans<<endl;

    }



    return 0;
}
