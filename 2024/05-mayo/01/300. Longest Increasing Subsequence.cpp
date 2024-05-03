class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int response = 1;

        vector<int>memo(nums.size()+5,1);

        for(int i = 1;i<nums.size();i++){
            for(int j=i;j>=0;j--){
                if(nums[j]<nums[i]){
                    memo[i] = max(memo[i],memo[j]+1);
                }
            }
            response = max(response,memo[i]);
        }

        return response;
    }
};