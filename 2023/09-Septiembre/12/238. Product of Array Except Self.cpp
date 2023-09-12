class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>answer;

        long long num = 1;

        int ceros = 0;
        int n =  nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                num*=nums[i];
            }
            else{
                ceros++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(ceros>1){
                answer.push_back(0);
            }
            else{
                if(nums[i]==0){
                    answer.push_back(num);
                }
                else{
                    if(ceros==0){
                        answer.push_back(num/nums[i]);
                    }
                    else{
                        answer.push_back(0);
                    }
                }
            }
        }
        return answer;
    }
};