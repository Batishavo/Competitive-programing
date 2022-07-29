#include<bits/stdc++.h>

using namespace std;

int t,
    n,
    lon;

string cad;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        cin>>cad;

        lon=0;

        for(int i=1;i<n;i++){

            if(cad[i]>cad[i-1]||cad[i]==cad[0]) {

                break;

            }

            lon = i;
        }

       // printf("-- %d", lon);
        for(int i=0;i<=lon;i++){
            cout<<cad[i];
        }
        for(int i=lon;i>=0;i--){
            cout<<cad[i];
        }
        printf("\n");
    }

    return 0;
}
