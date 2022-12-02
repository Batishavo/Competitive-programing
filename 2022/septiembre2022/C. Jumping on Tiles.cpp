#include<bits/stdc++.h>

using namespace std;


int t,
    cont,
    arr[300];

string cad;
vector <int> v[300];
vector<int>jumps;
int main(){

    scanf("%d",&t);

    while(t--){

        cin>>cad;

        for(int i=0;i<cad.size();i++){

            arr[cad[i]]++;
            v[cad[i]].push_back(i);

        }

        int num1=cad[0],num2=cad[cad.size()-1];
        cont=arr[num1];
        for(auto x:v[num1]){
            jumps.push_back(x);
        }
        printf("%d ",abs(num1-num2));

        while(num1!=num2){

            if(num1>num2){
                num1--;

            }
            else{
                num1++;
            }
            cont+=arr[num1];
            for(auto x:v[num1]){
                jumps.push_back(x);
            }
        }
        printf("%d\n",cont);

        for(auto x:jumps){
            printf("%d ",x+1);
        }
        printf("\n");
        for(int i='a';i<='z';i++){
            arr[i]=0;
            v[i].clear();
        }
        jumps.clear();

    }

    return 0;
}
