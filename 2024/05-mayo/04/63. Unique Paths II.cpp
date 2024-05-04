class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if(obstacleGrid[n-1][m-1]==1 || obstacleGrid[0][0]==1){
            return 0;
        }

        vector<vector<int>> memo(n+5,vector<int>(m+5,-1));

        return dp(n,m,0,0,obstacleGrid,memo);
    }
private:

    int dp(
            int &n,
            int &m,
            int row,
            int col,
            vector<vector<int>>& obstacleGrid,
            vector<vector<int>>& memo
        ){
        
        if(row == n-1 && col == m-1){
            return 1;
        }

        if(memo[row][col]!=-1){
            return memo[row][col];
        }

        int answer = 0;

        if(row+1<n && obstacleGrid[row+1][col] == 0 ){
            if(memo[row+1][col] == -1){
                memo[row+1][col] = dp(n,m,row+1,col,obstacleGrid,memo);
            }
            answer+= memo[row+1][col] ;
        }
        if(col+1<m && obstacleGrid[row][col+1] == 0){
            if(memo[row][col+1] == -1){
                memo[row][col+1] = dp(n,m,row,col+1,obstacleGrid,memo);
            }
            answer+=memo[row][col+1];
        }

        memo[row][col] = answer;
        return answer;

    }
};