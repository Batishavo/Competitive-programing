#include<bits/stdc++.h>

using namespace std;

int t,
    n,
    k,
    cont;

vector<int> fours,
            sums,
            mores;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&k);


            cont=0;
            int pos=0;
            fours.clear();
            sums.clear();
            mores.clear();

            bool flag = false;

            for(int i=1;i<=n;i++){

                if(i%4==0 && !flag){

                    fours.push_back(i);
                    cont++;

                }
                else if((i+k)%4==0  && !flag){
                    sums.push_back(i);
                    cont++;
                }
                else{
                    mores.push_back(i);
                }
                if(cont>=n/2){
                   flag = true;
                }

            }

            //cout<<cont<<endl;

            if(flag){
                 printf("YES\n");
                for(auto x: sums){

                    printf("%d %d\n",x ,mores[pos++]);

                }
                for(auto x: fours){

                    printf("%d %d\n",mores[pos++] ,x );

                }
            }
            else{
                 printf("NO\n");
            }



        }

    }

    return 0;
}
