class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int answer = nums[0];
        int tmp = nums[0];

        for(int i=1;i<n;i++){
            if(tmp<0){
                tmp = 0;
            }
            tmp+=nums[i];
            //cout<<answer<<" "<<tmp<<" "<<i<<" "<<nums[i]<<endl;
            answer = max(tmp,answer);
        }

        return answer;

    }
};