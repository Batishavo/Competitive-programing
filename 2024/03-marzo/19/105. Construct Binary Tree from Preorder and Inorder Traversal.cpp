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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int>positioInorder; 
        
        for(int i=0;i<preorder.size();i++){
            positioInorder[inorder[i]] = i;
        }

        int index = 0;

        return dp(preorder,positioInorder,index,0,preorder.size()-1);
    }

    TreeNode* dp(
        vector<int>& preorder,
        map<int,int>& positioInorder,
        int& index,
        int left,
        int right

    ) {

        if(left>right){
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[index++]);

        int mid = positioInorder[node->val];

        node->left = dp(preorder,positioInorder,index,left,mid-1);
        node->right = dp(preorder,positioInorder,index,mid+1,right);

        return node;
    }
};