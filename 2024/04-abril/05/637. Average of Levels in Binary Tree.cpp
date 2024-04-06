/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<pair<long long,long long>> memo;
        queue<pair<TreeNode*,long long>> bfs;
        
        vector<double>answer;

        if(root==NULL){
            return answer;
        }
        
        bfs.push({root,0});

        while(!bfs.empty()){

            TreeNode* node = bfs.front().first;
            long long currentLevel = bfs.front().second;

            //cout<<node->val<<" "<<currentLevel<<endl;

            bfs.pop();

            if(currentLevel>=memo.size()){
                memo.push_back({0,0});
            }

            memo[currentLevel].first+=node->val;
            memo[currentLevel].second++;

            if(node->left!=NULL){
                bfs.push({node->left,currentLevel+1});
            }
            if(node->right!=NULL){
                bfs.push({node->right,currentLevel+1});
            }


        }

        for(auto x:memo){
            double average = (double)x.first / (double)x.second;
            answer.push_back(average);
        }

        return answer;
    }
};