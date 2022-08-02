#include<bits/stdc++.h>

using namespace std;

const int limit = (10e6)+10;

int n,
    m,
    aux,
    pairsPlanks,
    fourPlanks,
    bucket[limit];

int main(){

    scanf("%d",&n);

    while(n--){

        scanf("%d",&aux);

        if(bucket[aux]%2==1){

            pairsPlanks++;

        }
        if(bucket[aux]%4==3){

            fourPlanks++;
        }
        bucket[aux]++;
    }

    scanf("%d",&m);

    while(m--){

        char tmp;

        cin>>tmp>>aux;

        if(tmp=='+'){

            if(bucket[aux]%2==1){

                pairsPlanks++;

            }
            if(bucket[aux]%4==3){

                fourPlanks++;
            }
            bucket[aux]++;

        }

        if(tmp=='-'){

            if(bucket[aux]%2==0){

                pairsPlanks--;

            }
            if(bucket[aux]%4==0){

                fourPlanks--;
            }

            bucket[aux]--;

        }

        if(fourPlanks>=1 && pairsPlanks>=4){

            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

    }


    return 0;
}
