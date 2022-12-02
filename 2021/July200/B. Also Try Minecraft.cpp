#include<bits/stdc++.h>

using namespace std;

const int limit = (10e5)+10;

int n,
    m,
    s,
    j,
    arr[limit];

long long sum,
          sum_right[limit],
          sum_left[limit];

int main(){

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){

        scanf("%d",&arr[i]);

    }

    sum=0;

    for(int i=1;i<=n-1;i++){

      if(arr[i]>arr[i+1]){

        sum+= arr[i]-arr[i+1];

      }

      sum_right[i+1]=sum;

    }

    sum=0;

    for(int i=n;i>1;i--){

        if(arr[i]>arr[i-1]){

           sum+= arr[i]-arr[i-1];

        }
        sum_left[i-1]=sum;

    }



    for(int i=0;i<m;i++){

        scanf("%d %d",&s,&j);
        //printf("\n--");
        if(s<j){

            printf("%lld\n",sum_right[j]-sum_right[s]);

        }
        else{

             printf("%lld\n",sum_left[j]-sum_left[s]);

        }


    }

    return 0;
}
