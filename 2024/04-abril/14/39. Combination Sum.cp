class Solution {

private:
map<string,bool>memo;

public:

    string vectorToString(vector<int>&combination){
        string cad;
        sort(combination.begin(),combination.end());
        for(int i=0;i<)
    }

    vector<vector<int>> dp(vector<int>& candidates, int &target,int sum,vector<int> combination){
        
        vector<int>answer;

        if(sum==targer){

        }

        for(int i=0;i<candidates.size();i++){
            if(sum+candidates[i]<=target){
                combination.push_back(candidates[i]);
                vector<int>tmp = dp(candidates,target,sum+candidates[i],combination);
                answer.insert(answer.end(),tmp.begin(),tmp.end());
                candidates.pop_back();
            }
        }

        return answer;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    }
};