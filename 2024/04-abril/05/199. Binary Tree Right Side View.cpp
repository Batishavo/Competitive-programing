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
    vector<int> rightSideView(TreeNode* root) {
        

        vector<int> answer ;

        if(root==NULL){
            return answer;
        }

        queue<pair<TreeNode*,int>>bfs;
        int level = -1;
        TreeNode *prev = NULL;

        bfs.push({root,0});
        //answer.push(root->val);

        while(!bfs.empty()){

            TreeNode* node = bfs.front().first;
            int currentLevel = bfs.front().second;
            bfs.pop();

            if(currentLevel!=level){
                if(prev!=NULL){
                    level = currentLevel;
                    answer.push_back(prev->val);
                }
                
            }

            if(node->left!=NULL){
                bfs.push({node->left,currentLevel+1});
            }
            if(node->right!=NULL){
                bfs.push({node->right,currentLevel+1});
            }

            prev=node;

        }

        if(answer.size()==0 || answer[answer.size()-1]!=prev->val){
            answer.push_back(prev->val);
        }

        return answer;
    }
};