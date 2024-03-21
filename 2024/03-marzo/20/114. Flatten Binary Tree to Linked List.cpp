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

    void dp(TreeNode* root){

        if(root == NULL){
            return;
        }


        dp(root->left);
        dp(root->right);
        
        TreeNode* tail=root;

        while(tail->left!=NULL){
            tail=tail->left;
        }
        if(tail->left != root->right)
            tail->left = root->right;

        root->right = NULL;

    }

    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
    
        dp(root);
    
        while(root!=NULL){
            //if(root->left !=NULL){
            swap(root->left,root->right);
            //}
            //cout<<root->val<<" "<<root->left<<" "<<root->right<<endl;
            root=root->right;
        }
    }
};