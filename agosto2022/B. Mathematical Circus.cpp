#include<bits/stdc++.h>

using namespace std;

int t,
    n,
    cont,
    pos;

long long k;

vector<int> fours,
            sums,
            mores;

void imprime(){
    for(auto x: sums){

        printf("%d %d\n",x ,mores[pos++]);

    }
    //printf("---\n");
    for(auto x: fours){

        printf("%d %d\n",mores[pos++] ,x );

    }
}

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %lld",&n,&k);


        cont=0;
        pos=0;
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
            imprime();
        }
        else{
            vector<int> dos,
                        aux;

            int bus=0;

             for(auto x :  mores){

                if(x%2==0 && cont<n/2 && bus!=2){
                    dos.push_back(x);
                    bus=2;
                    if(dos.size()%2==0){
                        cont++;
                    }
                }
                else if((x+k)%2==0 && cont<n/2  && bus!=1){

                    dos.push_back(x);
                    bus=1;

                    if(dos.size()%2==0){
                        cont++;
                    }

                }
                else{
                    mores.push_back(x);
                }

             }
             mores=aux;

             //cont+=min(dos.size(),masdos.size());

             //cout<<cont<<" "<<dos.size()<<" "<<masdos.size()<<endl;

             if(cont>=n/2){
                printf("YES\n");
                while(pos<dos.size()){

                    if(((dos[pos]+k)*dos[pos+1])%4==0){
                      //printf("--%d %d",dos[pos],dos[pos+1]);
                       printf("%d %d\n",dos[pos],dos[pos+1]);


                    }
                    else{
                        printf("%d %d\n",dos[pos+1],dos[pos]);
                    }
                     pos+=2;

                }
                //printf("%d---\n",cont);
                imprime();

             }
             else{
                 printf("NO\n");
             }

        }
    }


    return 0;
}
