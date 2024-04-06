class Trie{    
public:

    map<char,Trie*> dictionary;

    Trie(){}

    void insertWord(string word){
        
        Trie* current = this;

        for(char leter: word){
            if(current->dictionary[leter]==NULL){
                current->dictionary[leter] = new Trie();
            }
            current = current->dictionary[leter];
        }
        current->dictionary['*'] = new Trie();

    }

    bool search(string word){
        Trie * current = this;
        for(char leter: word){
            if(current == NULL || current->dictionary[leter]==NULL){
                return false;
            }
            current = current->dictionary[leter];
        }
        return current!=NULL && current->dictionary['*']!=NULL;
    }
};

class Solution {
public:

    const int moveRow[5]    = {1,0,-1, 0};
    const int moveColumn[5] = {0,1, 0,-1};

    void boardWords(
        int row,
        int column,
        int &n,
        int &m,
        string cad,
        vector<vector<char>>& board,
        map<string,bool>&used,
        vector<vector<bool>>&memo,
        vector<string> &currentWords
    ){
        
        if(!used[cad]){
            
            used[cad]=1;
            currentWords.push_back(cad);
        }

        for(int k=0;k<4;k++){
            
            int currentRow = row + moveRow[k];
            int currentColumn = column + moveColumn[k]; 

            if(
                currentRow>=0 &&
                currentRow<n &&
                currentColumn>=0 &&
                currentColumn<m &&
                memo[currentRow][currentColumn] == 0
            ){
                memo[currentRow][currentColumn] = 1;
                boardWords(
                    currentRow,
                    currentColumn,
                    n,
                    m,
                    cad+board[currentRow][currentColumn],
                    board,
                    used,
                    memo,
                    currentWords
                );
                memo[currentRow][currentColumn] = 0;
            }

        }


    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        Trie * trie = new Trie();

        int n = board.size();
        int m = board[0].size();

        map<string,bool>used;
        vector<vector<bool>>memo(n+5,vector<bool>(m+5,false));

        vector<string> currentWords;
        vector<string> answer;

        for(string word:words){
            trie->insertWord(word);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string cad = "";
                cad+=+board[i][j];
                memo[i][j]=1;
                boardWords(i,j,n,m,cad,board,used,memo,currentWords);
                memo[i][j]=0;
                for(string word:currentWords){
                    if(trie->search(word)){
                        answer.push_back(word);
                    }
                    
                }
                currentWords.clear();
            }
        }

        return answer;

    }
};
