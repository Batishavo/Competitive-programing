#include<bits/stdc++.h>

using namespace std;

const int limit=5000;

int p,q,l,r,cont,
    arrx[limit],
    arrz[limit][3];

int main(){

    scanf("%d %d %d %d",&p,&q,&l,&r);

    for(int i=0;i<p;i++){

        int a,b;
        cin>>a>>b;

        for(int j=a;j<=b;j++){
            arrx[j]=1;
        }
    }

    for(int i=0;i<q;i++){
        scanf("%d",&arrz[i][0]);
        scanf("%d",&arrz[i][1]);
    }

    for(int i=l;i<=r;i++){
        bool flag=false;
        for(int j=0;j<q;j++){
            for(int x=arrz[j][0];x<=arrz[j][1];x++){
                if(arrx[x+i]==1){
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        cont+=flag;
    }

    printf("%d\n",cont);


    return 0;
}
