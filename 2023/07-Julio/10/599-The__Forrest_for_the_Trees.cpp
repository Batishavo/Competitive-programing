#include <bits/stdc++.h>
using namespace std;

const int tam = 260;

int my_adjacent_mat[tam][tam];
int memo[tam];

void my_clean_adjacent_mat()
{
    for (int i = 'A'; i <= 'Z'; i++)
    {
        for (int j = 'A'; j <= 'Z'; j++)
        {
            my_adjacent_mat[i][j] = 0;
        }
    }
    for(int i='A';i<='Z';i++){
        memo[i]=0;
    }
}

bool is_tre(int pos){
    //cout<<endl<<(char)pos<<endl;
    for(int i='A';i<='Z';i++){
        //cout<<"X"<<endl;
       //printf("%d ",my_adjacent_mat[pos][i]);
        if(my_adjacent_mat[pos][i]==1){
            return true;
        }


    }
    //cout<<"Sale";
    return false;
}

void dfs(int pos){
    memo[pos]=1;
    for(int i='A';i<='Z';i++){
        if(my_adjacent_mat[pos][i]==1 && memo[i]==0){
            dfs(i);
        }
    }
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int my_tre=0,
        my_acorn=0,
        t;

    string cad;

    cin >> t;

    while (t--)
    {
        my_tre=0;
        my_acorn=0;
        my_clean_adjacent_mat();
        while(true){
            
            cin>>cad;
            //cout<<cad<<endl;
            if(cad[0]=='*'){
                break;
            }
            my_adjacent_mat[cad[1]][cad[3]]=1;
            my_adjacent_mat[cad[3]][cad[1]]=1;
        }
        cin>>cad;
        // for(int i='A';i<='Z';i++){
        //     for(int j='A';j<='Z';j++){
        //         cout<<my_adjacent_mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<cad.size();i+=2){
            //cout<<cad[i]<<endl;
            if(memo[cad[i]]==0){
                int pos = cad[i];
                if(is_tre(pos)){
                    //cout<<"LLega aqui";
                    my_tre++;
                    dfs(pos);
                }
                else{
                    my_acorn++;
                }
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n",my_tre, my_acorn);
    }

    return 0;
}