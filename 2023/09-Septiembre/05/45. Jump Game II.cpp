class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>memo(n,0);
        queue<int>jumps;
        jumps.push(0);
        while(!jumps.empty()){
            int actual = jumps.front();
            jumps.pop();
            int cont = memo[actual]+1;
            for(int i =min( actual+nums[actual],n-1);i>actual;i--){
                if(memo[i]!=0){
                    break;
                }
                memo[i]=cont;
                jumps.push(i);
            }
        }
        return memo[n-1];
    }
};