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

    bool flag = 1;

    int countNodes(TreeNode* root) {
        int left = 0;
        int right = 0;


        if(root!=NULL){
            if( root->left!=NULL){
                left = countNodes( root->left )+1;
            }
            if( root->right!=NULL){
                right = countNodes( root->right )+1;
            }
        }
        else{
            flag = 0;
        }
        
        int sum = left + right + flag;
        
        if(flag) flag = 0;
        
        return sum;
    }
};