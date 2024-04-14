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

private:
    TreeNode* createTree(vector<int>& nums,int left,int right){

        //TODO: is right the conditional?
        if(left>right){
            return NULL;
        }
        //TODO: Calaculate the mid;
        int mid =(left+right)/2;
        TreeNode* current = new TreeNode(nums[mid]);
        //TODO: is OK the left and right
        current->left  = createTree(nums,left,mid-1);
        current->right = createTree(nums,mid+1,right);

        return current;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        return createTree(nums,0,n-1);
    }
};