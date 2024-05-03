class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> answer;
        priority_queue<vector<int>, vector<vector<int>>, Sum> combination;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                vector<int> tmp;
                tmp.push_back(nums1[i]);
                tmp.push_back(nums2[j]);
                combination.push(tmp);
            }
        }

        while(k--){
            answer.push_back(combination.top());
            combination.pop();
        }

        return answer;
    }

private:
    struct Sum{
        bool operator()(vector<int> a ,vector<int> b){
            
            int sumA = a[0] + a[1];
            int sumB = b[0] + b[1];

            return sumA>sumB;
        }
    } ;
};