/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    

    int dp(TreeNode* root, TreeNode* p, TreeNode* q,int level,TreeNode* &answer,int maxLevel){

        int cont = 0;
        bool left = 0;
        bool right = 0;

        if(root == p || root == q){
            cont++;
        }

        if(root->left!=NULL){
            left=dp(root->left,p,q,level+1,answer,maxLevel);
        }
        if(root->right!=NULL){
            right=dp(root->right,p,q,level+1,answer,maxLevel);
        }

        cont+=left+right;

        if(cont>=2){
            if(level>maxLevel){
                answer = root;
                maxLevel = level;
            }
        }

        //cout<<root->val<<" "<<level<<" "<<cont<<endl;

        return cont;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* answer = root;
        int level = 0;
        dp(root, p, q,0,answer,level);
        return answer;
    }
};