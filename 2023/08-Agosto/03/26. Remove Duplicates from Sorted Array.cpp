class Solution {
public:


    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int pos = 0;
        
        map<int,bool>memo;

        for(int i=0;i<n;i++){
            if(memo[nums[i]]==0){
                //cout<<nums[i]<<endl;
                memo[nums[i]]=1;
                swap(nums[i],nums[pos]);
                pos++;
            }
        }

        return pos;
    }
};