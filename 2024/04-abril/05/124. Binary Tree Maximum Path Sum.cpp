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

    int answer;

    void preorder(TreeNode* root){

        if(root == NULL){
            return;
        }
        int answer = root->val;
        
       

        if(root->left!=NULL){
            int left=dp(root->left);
            answer = max(answer,answer+left);
            preorder(root->left);
        }
        if(root->right!=NULL){
            int right=dp(root->right);
            answer = max(answer,answer+right);
            preorder(root->right);
        }

        this->answer = this->answer = max(this->answer,answer);

    }

    int dp(TreeNode* root){

       
        if(root->left==NULL && root->right==NULL){
            this->answer = max(this->answer,root->val);
            return root->val;
        }

        int left;
        int right;
        bool flagLeft = 0;
        bool flagRight = 0;
        
        int answer = root->val;

        if(root->left!=NULL){
            flagLeft = 1;
            left = dp(root->left);
        }
        if(root->right!=NULL){
            flagRight = 1;
            right = dp(root->right);
        }

        if(flagLeft){
            answer = max(answer,left+root->val);
        }
        if(flagRight){
            answer = max(answer,root->val+right);
        }
        

        
        return answer;

    }

    int maxPathSum(TreeNode* root) {
         
        if(root==NULL){
            return 0;
        }

        this->answer = root->val;

        preorder(root);
        
        return this->answer;
    }
};