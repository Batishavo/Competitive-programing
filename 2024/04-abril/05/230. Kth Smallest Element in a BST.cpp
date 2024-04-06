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

    void dp(TreeNode* root, int k,int &level,int &answer){

        if(root->left!=NULL){
            dp(root->left,k,level,answer);
        }
        level++;
        if(level == k){
            answer = root->val;
        }
        if(root->right!=NULL){
            dp(root->right,k,level,answer);
        }

        
      

    }

    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        int level = 0;
        int answer = root->val;
        dp(root,k,level,answer);
        return answer;
    }
};