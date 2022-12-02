#include<bits/stdc++.h>

using namespace std;

int test,
    n,
    h,
    m,
    cont1 = 0,
    cont2 = 0,
    arr[100][100];

void clean(){

    for(int i=0;i<50;i++){

        for(int j=0;j<70;j++){

            arr[i][j]=0;
        }
    }

}

int main(){

    scanf("%d",&test);

    while(test--){

        scanf("%d %d %d",&n,&h,&m);

        for(int i=0;i<n;i++){

            int aux1,aux2;

            scanf("%d %d",&aux1,&aux2);

            arr[aux1][aux2]=1;

        }

        while(arr[h][m]==0){

            cont2++;

            if(cont2==60){

                cont1++;
                cont2=0;
            }

            m++;

            if(m==60){

                h++;

                m=0;

            }

            if(h==24){

                h=0;
            }


        }


        printf("%d %d\n",cont1,cont2);

        cont1=0;

        cont2=0;

        clean();

    }

    return 0;
}
