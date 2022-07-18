#include<bits/stdc++.h>

using namespace std;


char cad[1000];

void ini_cad(){

    for(int i=0;i<=50;i++){

        cad[i]='B';

    }

}

int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        ini_cad();

        int n,
            m;

        scanf("%d %d",&n,&m);

        for(int i=0;i<n;i++){

            int aux;

            scanf("%d",&aux);



            if(aux<m+1-aux && cad[aux]=='B'){

                cad[aux]='A';
            }
            else if(cad[m+1-aux]=='A'){

                cad[aux]='A';

            }
            else{

                cad[m+1-aux]='A';

            }
        }

        for(int i=1;i<=m;i++){

            printf("%c",cad[i]);

        }

        printf("\n");

    }

    return 0;
}
