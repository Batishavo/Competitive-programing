/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    int inorder(Node* root,int pos,map<int,queue<Node*>>& bucket){
        if(root==NULL){
            return 0;
        }
        bucket[pos].push(root);
        return max(inorder(root->left,pos+1,bucket)+1,inorder(root->right,pos+1,bucket)+1);
    }

    Node* connect(Node* root) {
        map<int,queue<Node*>>bucket;
        int n = inorder(root,0,bucket);
        for(int i=0;i<n;i++){
            Node* tmp;
            if(!bucket[i].empty()){
                tmp = bucket[i].front();
                bucket[i].pop();
            }
            while(!bucket[i].empty()){
                tmp->next=bucket[i].front();
                tmp=bucket[i].front();
                bucket[i].pop();
            }
        }
        
        return root;
    }
};