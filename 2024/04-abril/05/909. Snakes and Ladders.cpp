class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        //cout<<"n = "<<n<<endl;

        vector<int> plainBoard;
        vector<int> memo(n*n+10,INT_MAX);
    
        queue<pair<int,int>>bfs;

        bool canWin = false;
        bool isReverse = false;

        for(int i=n-1;i>=0;i--){
            if(isReverse){
                reverse(board[i].begin(),board[i].end());
            }
            for(int j=0;j<n;j++){
                plainBoard.push_back(board[i][j]);
            }
            isReverse = !isReverse;
        }

        bfs.push({0,0});
        memo[0]=0;

        while(!bfs.empty()){

            int square = bfs.front().first;
            int moves = bfs.front().second;

            if(square == n*n-1){
                canWin = true;
            }

            //cout<<square<<" "<<moves<<endl;

            bfs.pop();

            for(int i = 1;i<=6;i++){
                
                int newSquare = square + i;
                
                if(newSquare >= n*n ){
                    break;
                }
                if(plainBoard[newSquare]!=-1){
                    newSquare = plainBoard[newSquare]-1;
                }
                if( memo[newSquare]>moves+1 ){
                    memo[newSquare]=moves+1;
                    bfs.push({newSquare,moves+1});
                }

            }


        }
        /*for(int i=0;i<n*n;i++){
            cout<<i<<" "<<memo[i]<<endl;
        }*/
        //cout<<"llega";
        return canWin?memo[n*n-1]:-1;
    }
};