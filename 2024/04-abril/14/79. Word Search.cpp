class Solution {
private:

const int moveRow[5]    = {1,0,-1,0};
const int moveColumn[5] = {0,1,0,-1};

bool searchWord(
    int row,
    int column,
    vector<vector<char>>& board,
    string &word,
    int pos,
    vector<vector<bool>>&memo,
    int &n,
    int &m
){
    
    if(pos==word.size()){
        
        return true;
    }
    //cout<<row << " "<< column<<" "<<word[pos]<<endl;

    for(int i=0;i<4;i++){
        
        int currentRow = row +  moveRow[i];
        int currentColumn = column + moveColumn[i];
        
        if(
            currentRow>= 0 &&
            currentRow<n &&
            currentColumn >=0 &&
            currentColumn < m &&
            !memo[currentRow][currentColumn] && 
            board[currentRow][currentColumn] == word[pos]
        ){
            memo[currentRow][currentColumn] = 1;
            if(searchWord(currentRow,currentColumn,board,word,pos+1,memo,n,m)){
                return true;
            }
            memo[currentRow][currentColumn] = 0;
        }
    }

    return false;
}

public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int row = board.size();
        int column = board[0].size();

        vector<vector<bool>>memo(row+5,vector<bool>(column+5,false));

        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(board[i][j]==word[0]){
                    //cout<<i<<" "<<j<<" "<<word[0]<<endl;
                    memo[i][j]=1;
                    if(
                        searchWord(
                            i,
                            j,
                            board,
                            word,
                            1,
                            memo,
                            row,
                            column
                        )
                    ){
                        
                        
                        return true;
                    }
                    memo[i][j]=0;
                }
            }   
        }

        return false;

    }
};