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

    bool dp(
        TreeNode* leftt,
        TreeNode* rightt
    ){

        if(leftt==NULL && rightt == NULL){
            return true;
        }
        if(leftt==NULL || rightt == NULL || leftt->val!=rightt->val){
            return false;
        }

        return dp(leftt->left,rightt->right) && dp(leftt->right,rightt->left) ;

    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }

        return dp(root->left,root->right);

    }
};