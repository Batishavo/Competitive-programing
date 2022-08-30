#include<bits/stdc++.h>

using namespace std;

map<string,int>used;

vector<string> dude1,
               dude2,
               dude3;
string aux;

int n,t,d1,d2,d3;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){

                cin>>aux;

                switch (i){
                    case 0:
                        dude1.push_back(aux);
                        break;

                    case 1:
                        dude2.push_back(aux);
                        break;

                    case 2:
                        dude3.push_back(aux);
                        break;
                }
                //dude1.push_back(aux);
                used[aux]++;
            }

        }
        d1=0;d2=0;d3=0;
        for(int i=0;i<n;i++){

           if(used[dude1[i]]==1){
             d1+=3;
           }
           else if(used[dude1[i]]==2){
            d1++;
           }
        }
        for(int i=0;i<n;i++){
           if(used[dude2[i]]==1){
             d2+=3;
           }
           else if(used[dude2[i]]==2){
            d2++;
           }

        }
        for(int i=0;i<n;i++){
            if(used[dude3[i]]==1){
             d3+=3;
           }
           else if(used[dude3[i]]==2){
            d3++;
           }
        }

        printf("%d %d %d\n",d1,d2,d3);
        used.clear();
        dude1.clear();
        dude2.clear();
        dude3.clear();

    }

    return 0;
}
