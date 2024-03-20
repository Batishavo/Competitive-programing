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

    TreeNode* dp(
        vector<int>& inorder, 
        vector<int>& postorder,
        map<int,int>& bucket,
        int &index,
        int left,
        int right
    ){
        if(left>right || index<0){
            return NULL;
        }
        
        TreeNode* nodo = new TreeNode();
        nodo->val = postorder[index--];

        int mid = bucket[nodo->val];

        nodo->right= dp(inorder,postorder,bucket,index,mid+1,right);
        nodo->left = dp(inorder,postorder,bucket,index,left,mid-1);

        return nodo;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>bucket;
        for(int i=0;i<inorder.size();i++){
            bucket[inorder[i]] = i;
        }
        int index = inorder.size()-1;
        return dp(inorder,postorder,bucket,index,0,inorder.size()-1);
    }
};