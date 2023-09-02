class Solution {
public:

    const int limit = 10e4+10;

    vector<int> memo;

    bool posible(int pos,int n,vector<int>& nums){
        if(pos==n){
            return true;
        }

        bool flag = false;

        for(int i = nums[pos];i>=1;i--){
            
            if(pos+i>=n){
                return true;
            }

            if(memo[pos+i]==0){
                memo[pos+i]=1;
                flag = flag || posible(pos+i,n,nums);
            }
            else{
                break;
            }
        }
        return flag;
    }
    
    bool canJump(vector<int>& nums) {
        memo = vector<int>(limit,0);      
        return posible(0,nums.size()-1,nums);
    }

};