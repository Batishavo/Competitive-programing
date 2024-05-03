class Solution {
public:
    int rob(vector<int>& nums) {
        fill(memo, memo + 105, -1);
        return dp(nums,0);
    }
private:

    int memo[105];

    int dp(vector<int>& nums,int pos){
        
        if(pos >= nums.size()){
            return 0;
        }

        // Si ya hemos calculado el resultado para esta posición, lo retornamos desde el memo
        if(memo[pos] != -1){
            return memo[pos];
        }
    
        // Calculamos el resultado y lo almacenamos en el memo
        memo[pos] = max(dp(nums, pos + 1), dp(nums, pos + 2) + nums[pos]);
        return memo[pos];
    }
};