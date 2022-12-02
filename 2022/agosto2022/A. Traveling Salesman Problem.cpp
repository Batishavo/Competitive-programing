#include<bits/stdc++.h>

using namespace std;

int n,
    t,
    x,
    y,
    maxX,
    minX,
    minY,
    maxY;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        maxX=0;
        minX=0;
        minY=0;
        maxY=0;

        for(int i=0;i<n;i++){

            scanf("%d %d",&x,&y);

            minX = min(x, minX);
            maxX = max(x, maxX);
            minY = min(y, minY);
            maxY = max(y, maxY);

        }


        //printf("%d %d %d %d\n",maxX , maxY , minX ,minY);

        printf("%d\n",2 * (- minX - minY + maxX + maxY ));


    }

    return 0;
}
