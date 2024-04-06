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

    bool dp(TreeNode* root , int up, int down,bool flagUp,bool flagDown){
        bool left = true;
        bool right = true;
        bool current = true;

        //cout<<root->val<<" "<<up<<" "<<down<<endl;

        if(root->left!=NULL){
            current = current && root->val>root->left->val;
            left = dp(root->left,root->val,down,0,flagDown);
        }
        if(root->right!=NULL){
            current = current && root->val<root->right->val;
            right = dp(root->right,up,root->val,flagUp,0);
        }
        current = 
            current &&  
            (root->val<up || flagUp) &&  
            (root->val>down || flagDown)
        ;

        //cout<<left<<" "<<right<<" "<<current<<endl;
        return left && right && current;
    }

    bool isValidBST(TreeNode* root) {
        
        if(root==NULL || (root->left == NULL && root->right == NULL)){
            return true;
        }

        int up   = INT_MAX;
        int down = INT_MIN;

        return dp(root,up,down,1,1);
        
    }
};