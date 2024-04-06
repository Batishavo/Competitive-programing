class Solution {
public:

    const int movRow[5]    = {1,0,-1,0};
    const int movColumn[5] = {0,1,0,-1};

    void isFliped(
        vector<vector<char>>& board,
        int i,
        int j,
        int row,
        int column,
        vector<vector<bool>> &dontFlip,
        vector<vector<bool>> &memo
    ){
        bool flag = false;
        queue<pair<int,int>> bfs;
        stack<pair<int,int>> used;
        memo[i][j] = true;

        bfs.push({i,j});

        while(!bfs.empty()){
            
            int currentRow = bfs.front().first;
            int currentColumn = bfs.front().second;

            bfs.pop();
            used.push({currentRow,currentColumn});

            for(int k=0;k<4;k++){
                
                int newRow = currentRow+movRow[k];
                int newColumn = currentColumn+movColumn[k];

                if(
                    newRow>=0&&
                    newRow<row&&
                    newColumn>=0&&
                    newColumn<column
                ){
                    if( 
                        board[newRow][newColumn]=='O'&&
                        memo[newRow][newColumn]==0
                    ){
                        memo[newRow][newColumn]=1;
                        bfs.push({newRow,newColumn});
                    }
                   
                }
                else{
                    flag = true;
                }
            }
        }

        if(flag){
            while(!used.empty()){
                int currentRow = used.top().first;
                int currentColumn = used.top().second;
                used.pop();
                dontFlip[currentRow][currentColumn] = 1;
            }
        }
        else{
            while(!used.empty()){
                int currentRow = used.top().first;
                int currentColumn = used.top().second;
                used.pop();
                board[currentRow][currentColumn] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        
        int row = board.size();
        int column = board[0].size();
        
        vector<vector<bool>>memo(row+5,vector<bool>(column,false));
        vector<vector<bool>> dontFlip(row+5,vector<bool>(column,false));

        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(board[i][j] == 'O' && dontFlip[i][j]==false ){
                    isFliped(board,i,j,row,column,dontFlip,memo);
                }
            }
        }

    }
};