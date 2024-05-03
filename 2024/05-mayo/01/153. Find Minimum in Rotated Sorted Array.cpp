class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }

        int n = nums.size()-1;
        int left = 1;
        int right = n-1;
        
        if(
            nums[0]<nums[n] &&
            nums[0]<nums[1]
        ){
            return nums[0];
        }
        if(
            nums[n]<nums[0] &&
            nums[n]<nums[n-1]
        ){
            return nums[n];
        }

        while(left<=right){
            
            int mid = ( left + right ) / 2;

            if(
                nums[mid]<nums[mid-1]
            ){  
                return nums[mid];
            }
            else if(
                nums[mid]<nums[0] &&
                nums[mid]<nums[n]
            ){ 
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }

        }

        return -1;
    }
};