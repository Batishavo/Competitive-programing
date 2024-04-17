class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
      int total      = 0;
      int maxSum     = nums[0];
      int currentMax = 0;
      int minSum     = nums[0];
      int currentMin = 0;
      int n          = nums.size();

      for(int i=0;i<n;i++){
        currentMax = max(currentMax+nums[i],nums[i]);
        maxSum     = max(maxSum, currentMax);
        currentMin = min(currentMin+nums[i],nums[i]);
        minSum     = min(minSum,currentMin);
        total     += nums[i];
      }

      return maxSum>0 ? max(maxSum,total-minSum) : maxSum;

    } 
};