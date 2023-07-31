#include<bits/stdc++.h>

using namespace std;

const int limit = 10e3+10;

int mov_i[10]={1,0,-1, 0};
int mov_j[10]={0,1, 0,-1};

int bfs(int i,int j,string cad[],int n){

    vector<vector<int>>memo(n+10,vector<int>(n+10,0));

    queue<pair<int,int>> my_queue;

    my_queue.push({i,j});

    memo[i][j]=1;

    while(!my_queue.empty()){
        
        int actual_i = my_queue.front().first;
        int actual_j = my_queue.front().second;
        
        my_queue.pop();

        for(int k=0;k<4;k++){
            
            int pos_i = actual_i+mov_i[k];
            int pos_j = actual_j+mov_j[k];
            
            if(pos_i>=0 && pos_i<n && pos_j>=0 && pos_j<n){
                if(cad[pos_i][pos_j]=='3'){
                    return memo[actual_i][actual_j];
                }
                else if(memo[pos_i][pos_j]==0){
                    my_queue.push({pos_i, pos_j});
                    memo[pos_i][pos_j]=memo[actual_i][actual_j]+1;
                }
            }
        }

    }

    return 0;

}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int answer;

    string cad[limit];

    while(cin>>n){

        answer = 0;

        for(int i=0;i<n;i++){
            cin>>cad[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cad[i][j]=='1'){
                    int actual = bfs(i,j,cad,n);
                    answer = max(answer,actual);
                }
            }
        }

        cout<<answer<<endl;

    }

    return 0;
}