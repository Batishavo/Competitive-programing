#include<bits/stdc++.h>

using namespace std;

int test,
    my_key,
    arr[5];

bool posible(){

    int num=1;

    for(int i=0;i<3;i++){

        my_key=arr[my_key];

        if(my_key!=0){
            num++;
        }

    }

    return num==3;
}

int main(){

    scanf("%d",&test);

    while(test--){

        scanf("%d",&my_key);

        for(int i=1;i<=3;i++){

            scanf("%d",&arr[i]);

        }

        if(posible()){

            printf("YES\n");

        }
        else{

            printf("NO\n");

        }


    }

    return 0;
}
