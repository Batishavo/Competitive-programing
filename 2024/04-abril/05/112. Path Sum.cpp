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

    bool dp(TreeNode* root, int targetSum,int sum){
        
        if(root->left==NULL && root->right==NULL){

            return sum+root->val == targetSum;
        }

        bool left = false;
        bool right = false;


        if(root->left!=NULL){
            left = dp(root->left,targetSum,sum+root->val);
        }
        if(root->right!=NULL){
            right = dp(root->right,targetSum,sum+root->val);
        }

        return  left || right ;

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL){
            return false;
        }        


        return dp(root,targetSum,0);

    }
};