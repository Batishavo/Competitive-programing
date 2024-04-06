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

    vector<int> nums;

    void dp(TreeNode* root){
        nums.push_back(root->val);
        if(root->left!=NULL){
            dp(root->left);
        }
        if(root->right!=NULL){
            dp(root->right);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int answer = INT_MAX;
        dp(root);
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            int num = abs(nums[i]-nums[i-1]);
            answer = min(answer,num);
        }
        return answer;
    }
};