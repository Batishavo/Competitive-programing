class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size()-1;

        if(nums.size()==1){
            return 0;
        }
        if(nums.size()==2){
            //cout<<"entra"<<endl;
            return isValid(0,nums)?0:1;
        }

        while(left<=right){
            
            int mid = (left+right)/2;

            //cout<<mid<<endl;

            if(isValid(mid,nums)){
                return mid;
            }
            //TODO: Movemente
            else if(move(mid,nums)){
                left = mid + 1;
            }
            else{
               right = mid - 1;
            }

        }
        
        return left;
    }
private:

    bool isValid(int pos,vector<int>& nums){

        int n = nums.size()-1;

        if(pos == 0) {
            return nums[1] < nums[0];
        }
        else if(pos == n){
            return nums[n - 1] > nums[n - 2];    
        }

        return nums[pos] > nums[pos - 1] && nums[pos] > nums[pos + 1];

    }

    bool move(int pos,vector<int>& nums){
        int n = nums.size()-1;
        if(
            (pos==0 && nums[1]>nums[0]) || 
            nums[pos]<nums[pos+1]
        ){
            return true;
        }
        return false;
    }
};