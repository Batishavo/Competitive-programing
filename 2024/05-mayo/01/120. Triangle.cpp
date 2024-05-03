class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //cout<<triangle.size()<<endl;

        vector<vector<int>>memo(triangle.size()+5,vector<int>(triangle.size()+5,INT_MAX));

        return dp(0,0,triangle,memo);
    }
private:

    

    int dp(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& memo){
        

        if(i>=triangle.size()){
            return 0;
        }
        if(memo[i][j]!=INT_MAX){
            return memo[i][j];
        }
        
        if(triangle.size() && memo[i+1][j]==INT_MAX){
            memo[i+1][j] = dp(i+1,j,triangle,memo)+triangle[i][j];
        } 
        if(memo[i+1][j+1]==INT_MAX){
            memo[i+1][j+1] = dp(i+1,j+1,triangle,memo)+triangle[i][j];
        }

        return min(
            memo[i+1][j],
            memo[i+1][j+1]
        );

    }
};