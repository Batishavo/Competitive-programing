class Solution {
public:

    void markIsland(
        int i,
        int j, 
        vector<vector<char>>& grid,
        vector<vector<bool>>& memo,
        int moveRow[],
        int moveColumn[],
        int columnSize,
        int rowSize
    ){
        queue<pair<int,int>> bfs;
        bfs.push({i,j});

        while(!bfs.empty()){
            
            int row = bfs.front().first;
            int column = bfs.front().second;
            
            memo[row][column]=1;

            bfs.pop();

            for(int i=0;i<4;i++){

                int currentRow = row + moveRow[i];
                int currentColumn = column + moveColumn[i];
            
                if(
                    currentRow >= 0 && 
                    currentRow < rowSize &&
                    currentColumn >= 0 &&
                    currentColumn < columnSize &&
                    memo[currentRow][currentColumn] == 0 &&
                    grid[currentRow][currentColumn] == '1'
                ){
                    memo[currentRow][currentColumn] = 1;
                    bfs.push({currentRow,currentColumn});
                }
            }

        }

    }

    int numIslands(vector<vector<char>>& grid) {

        int counter = 0;

        int columnSize = grid[0].size();
        int rowSize = grid.size();
    
        cout<<columnSize<<" "<<rowSize<<endl;

        int moveColumn[10]= {0,1,0,-1};  
        int moveRow[10]  = {1,0,-1,0};
        
        vector<vector<bool>> memo(rowSize+10, vector<bool>(columnSize+10, false));

        for(int i=0;i<rowSize;i++){
            for(int j=0;j<columnSize;j++){
                if(grid[i][j]=='1' && memo[i][j]==0){
                    counter++;
                    memo[i][j]=1;
                    markIsland(i,j,grid,memo,moveRow,moveColumn,columnSize,rowSize);

                }
            }
        }

        return counter;

    }
};