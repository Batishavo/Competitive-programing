#include<bits/stdc++.h>

using namespace std;

const int limit = 2*10e5+10;

int employes[limit];
list<int> task;

int main(){

    int test;
    scanf("%d",&test);

    while(test--){

        int n,m;

        scanf("%d %d",&n,&m);

        for(int i=0;i<m;i++){
            int aux;
            scanf("%d",&aux);
            task.push_back(aux);
        }
       task.sort();


       for (list<int>::iterator i=task.begin(); i!=task.end(); i++)
            cout << *i << " ";

            cout << endl;
    }


    return 0;
}
