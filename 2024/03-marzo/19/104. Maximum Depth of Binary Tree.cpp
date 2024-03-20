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

    int dp(TreeNode* nodo,int sum){
        if(nodo == NULL){
            return sum;
        }

        return(max(dp(nodo->left,sum+1),dp(nodo->right,sum+1)));
    }

    int maxDepth(TreeNode* root) {
        return dp(root,0);
    }
};