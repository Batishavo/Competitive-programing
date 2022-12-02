#include<bits/stdc++.h>

using namespace std;

int test,
    n,
    m;

string cad1,
       cad2;

bool flag;

int main(){

    scanf("%d",&test);

    while(test--){

        flag=true;

        //scanf("%d %d",&n,&m);
        cin>>n>>m;
        cin>>cad1>>cad2;

        while(m>0){

             //printf("**%d %d\n",n,m);

            if(cad1[n-1]!=cad2[m-1] ){


                if(m-1==0){

                    flag=false;

                    for(int i=n-2;i>=0;i--){

                        if(cad1[i]==cad2[m-1]){

                            flag=true;
                        }

                    }

                }
                else{

                    flag=false;
                }

                break;
            }

            n--;
            m--;
        }

        printf((flag==true?"YES\n":"NO\n"));

    }

    return 0;
}
