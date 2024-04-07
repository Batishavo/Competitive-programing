class Solution {
private:
    int memo[10];
public:
    vector<vector<int>> dp(vector<int>& nums,int pos,vector<int>permutation){
        
        //cout<<pos<<endl;

        vector<vector<int>> answer;
        
        if(pos==nums.size()){
            answer.push_back(permutation);
            return answer;
        }

        for(int i=0;i<nums.size();i++){
            if(memo[i]==0){
                //cout<<pos<<" "<<nums[i]<<endl;
                memo[i]=1;
                permutation.push_back(nums[i]);
                vector<vector<int>> tmp = dp(nums,pos+1,permutation);
                answer.insert(answer.end(),tmp.begin(),tmp.end());
                memo[i]=0;
                permutation.pop_back();
            }
        }
        
        return answer;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return dp(nums,0,vector<int>());      
    }
};