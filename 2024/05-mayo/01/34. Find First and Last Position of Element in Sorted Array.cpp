class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return{
                binarySearch(nums,target,1),
                binarySearch(nums,target,2)
            }
        ;
            
    }

private:
    
    int binarySearch(vector<int>& nums,int target,int tipe){

        int left = 0;
        int right = nums.size()-1;

        while(left<=right){

            int mid = (left + right) / 2;
            
            if(nums[mid] == target){

                if(tipe == 2 ){
                    if(mid == nums.size()-1 || nums[mid+1]!=target){
                        return mid;
                    }
                    left = mid +1;
                }
                else{
                    if(mid == 0 || nums[mid-1] != target){
                        return mid;
                    }
                    right = mid -1;
                }
            }
            else if(nums[mid]>target){
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }

        }

        return -1;

    }
};