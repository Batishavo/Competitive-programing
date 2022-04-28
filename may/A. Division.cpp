#include<bits/stdc++.h>

using namespace std;

int main(){

    int li_cases;

    scanf("%d",&li_cases);

    while( li_cases-- ){

     int li_case,li_result;
     scanf("%d",&li_case);

     if(li_case>=1900){

        li_result = 1;

     }
     else if( li_case <= 1899 && li_case >= 1600 ){
        li_result = 2;
     }
     else if(li_case <= 1599 && li_case >= 1400 ){
        li_result = 3;
     }
     else{
        li_result = 4;
     }

        printf("Division %d\n",li_result);
    }
    return 0;
}
