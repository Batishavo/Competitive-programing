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
class BSTIterator {
public:
    
    stack<TreeNode*> inOrder;

    void putNodes(TreeNode* node){
        while(node!=NULL){
            inOrder.push(node);
            node=node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        putNodes(root);
    }
    
    int next() {

        TreeNode* node = inOrder.top();
        int val=node->val;

        inOrder.pop();

        if(node->right!=NULL){
            putNodes(node->right);
        }

        return val;

    }
    
    bool hasNext() {
        return !inOrder.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */