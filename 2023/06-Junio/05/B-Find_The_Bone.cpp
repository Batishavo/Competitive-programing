#include<bits/stdc++.h>

using namespace std;

const int limit = 10e6+10;

int n,
    m,
    k,
    p1,
    p2,
    aux,
    pos = 1,
    memo[limit];

bool flag = 1;

int main(){

    scanf("%d %d %d",&n,&m,&k);

    for(int i=0;i<m;i++){
        scanf("%d",&aux);
        memo[aux] = 1;
    }

    for(int i=0;i<k;i++){

        if(memo[pos]==1){
            flag = 0;
        }
        
        scanf("%d %d",&p1,&p2);

        if(flag){

            if(pos==p1){
                pos = p2;
            }
            else if(pos==p2){
                pos = p1;
            }

        }

    }

    cout << pos<<endl;

    return 0;
}