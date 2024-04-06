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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<pair<TreeNode*,int>>bfs;

        vector<vector<int>> answer;

        bool zizag = 0;

        if(root==NULL){
            return answer;
        }

        bfs.push({root,0});

        while(!bfs.empty()){

            TreeNode* node = bfs.front().first;
            int currentLevel = bfs.front().second;

            bfs.pop();
            
            if(answer.size()<=currentLevel){
                vector<int> tmp;
                answer.push_back(tmp);
            }

            answer[currentLevel].push_back(node->val);

            
            if(node->left!=NULL){
                bfs.push({node->left,currentLevel+1});
                
            }
            if(node->right!=NULL){
                bfs.push({node->right,currentLevel+1});
                
            }
          
        }

        for(int i=0;i<answer.size();i++){
            if(zizag){
                reverse(answer[i].begin(),answer[i].end());
            }
            zizag = !zizag;
        }

        return answer;

    }
};