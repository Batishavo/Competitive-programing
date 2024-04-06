/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    void createNodes(Node* node,Node* nodeClone, map<int,Node*>&memo){
        
        vector<Node*> neighborsClones;
        nodeClone->val = node->val;

        for(auto x:node->neighbors){
            
            if(memo[x->val]==NULL){
                Node* newNode = new Node( x->val);
                memo[x->val]=newNode;
                createNodes(x,newNode,memo);
        
            }
            neighborsClones.push_back(memo[x->val]);
        }
        nodeClone->neighbors = neighborsClones;
    }

    Node* cloneGraph(Node* node) {
        
        if(node==NULL){
            return NULL;
        }

        map<int,Node*>memo;
        Node* answer = new Node( node->val);
        memo[node->val] = answer;
        createNodes(node,answer,memo);

        return answer;
    }
};