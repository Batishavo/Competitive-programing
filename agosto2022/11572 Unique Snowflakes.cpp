#include<bits/stdc++.h>

using namespace std;

int t,
    n,
    aux,
    cont,
    maximo,
    repeatedPackage;

map<int,int>use;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        cont   = 0;
        maximo = 0;
        repeatedPackage = 0;
        use.clear();
        for(int i=1;i<=n;i++){

           scanf("%d",&aux);

           if(use[aux]){

                repeatedPackage = max(repeatedPackage, use[aux]);
                cont = i -repeatedPackage -1;
           }
            cont++;
            maximo=max(maximo , cont);
            use[aux] = i;

        }
        printf("%d\n",maximo);

    }



    return 0;
}
