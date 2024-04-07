class Solution {

public:
    
    vector<vector<int>>dp(int ini,int n,int k,vector<int>num){
        
        vector<vector<int>> answer;
        if(k==0){
            answer.push_back(num);
            return answer;
        }

        for(int i=ini;i<=n;i++){
            num.push_back(i);
            vector<vector<int>> tmp = dp(i+1,n,k-1,num);
            answer.insert(answer.end(),tmp.begin(),tmp.end());
            num.pop_back();
        }

        return answer;
    }

    vector<vector<int>> combine(int n, int k) {

            
        return dp(1,n,k,vector<int>());

    }
};