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

    int dp(TreeNode* root,int total){

        int left = 0;
        int right = 0;

        if(root==NULL){
            return 0;
        }

        if(root->left==NULL && root->right==NULL){
            return total*10+root->val;
        }

        if(root->left!=NULL){
            left = dp(root->left,total*10+root->val);
        }
        if(root->right!=NULL){
            right = dp(root->right,total*10+root->val);
        }

        return left + right ;
    }

    int sumNumbers(TreeNode* root) {
        return dp(root,0);
    }
};