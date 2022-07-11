#include<bits/stdc++.h>
using namespace std;

int used [300];

int main(){

    int test;

    scanf("%d",&test);

    for (int x = 0; x < test; x++) {

        string cad;

        cin>>cad;

        int dif=0;
        int total=0;

        for (int i = 0; i < cad.length(); i++) {
            if(used[cad[i]]==0){
                dif++;
                used[cad[i]]=1;
            }
            if(dif>3){
                total++;
                dif=1;

                for(int j='a';j<='z';j++){
                    used[j]=0;
                }
                 used[cad[i]]=1;
            }
           // printf("%d %d %c\n",dif,total,cad[i]);

        }
        printf("%d \n",total+1);
        for(int j='a';j<='z';j++){
            used[j]=0;
        }

    }


    return 0;
}


