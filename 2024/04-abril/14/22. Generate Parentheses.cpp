class Solution {

private:

    vector<string> parenthesis(int &n,int open,int close,int posible,string cad){
        
        vector<string> answer;
        
        if(open==n && close ==n && posible == 0){
            answer.push_back(cad);
            return answer;
        }

        if(open+1<=n && posible+1<=n){
            vector<string> anser_left = parenthesis(n,open+1,close,posible+1,cad+'(');;
            answer.insert(answer.end(),anser_left.begin(),anser_left.end());
        }
        if(close+1<=n && posible-1>=0){
            vector<string> answer_right = parenthesis(n,open,close+1,posible-1,cad+')');
            answer.insert(answer.end(),answer_right.begin(),answer_right.end());
        }

        return answer;

    }

public:
    vector<string> generateParenthesis(int n) {
        return parenthesis(n,0,0,0,"");
    }
};