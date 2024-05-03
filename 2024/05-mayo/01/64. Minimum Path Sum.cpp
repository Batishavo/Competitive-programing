class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> memo (n+5,vector<int>(m+5,-1));

        queue<pair<int,int>> bfs;
        
        memo[0][0] = grid[0][0];

        bfs.push({0,0});

        while(!bfs.empty()){

            int row = bfs.front().first;
            int column = bfs.front().second;
            int sum = memo[row][column];

            bfs.pop();

            if(
                row+1<n &&
                (memo[row+1][column] == -1 || memo[row+1][column]>sum+grid[row+1][column]) 
            ){
                memo[row+1][column] = sum+grid[row+1][column];
                bfs.push({row+1,column});
            }
            if(
                column+1<m &&
                (memo[row][column+1] == -1 || memo[row][column+1]>sum+grid[row][column+1]) 
            ){
                memo[row][column+1] = sum+grid[row][column+1];
                bfs.push({row,column+1});
            }

             
            //cout<<row<<" "<<column<<" "<<sum<<endl;
           
            //cout<<"--------"<<endl;
        }

       /*for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<memo[i][j]<<" ";
                }
                cout<<endl;
            }*/

        return memo[n-1][m-1];

    }
};