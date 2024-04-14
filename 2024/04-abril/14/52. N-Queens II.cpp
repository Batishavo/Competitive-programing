class Solution {
private:

    const int moveRow[10]    = {1 , 0,-1, 0, 1,-1, 1,-1};
    const int moveColumn[10] = {0 , 1, 0,-1, 1,-1,-1, 1}; 
    
    bool chessboard[15][15];

    bool isPosibleQueenHere(
        int row,
        int column,
        int n
    ){
       
        for(int i = 0;i<8;i++){
            
            int currentRow = row+moveRow[i];
            int currentColumn = column+moveColumn[i];

            while(
                currentRow>=0 &&
                currentRow<n &&
                currentColumn >=0 &&
                currentColumn <n
                
            ){
                if(chessboard[currentRow][currentColumn]){
                    return false;
                }

                currentRow    += moveRow[i];
                currentColumn += moveColumn[i];
            }
        }

        return true;
    }

    int dp(int n,int queens,int currentRow){

        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<chessboard[i][j];
            }
            cout<<endl;
        }
        cout<<"----"<<queens<<endl;*/

        int cont = 0;

        if(queens == n){
            return 1;
        }

        for(int row = currentRow;row<n;row++){
            for(int column = 0;column<n;column++){
                
                if( !chessboard[row][column] && isPosibleQueenHere(row,column,n)){
                    chessboard[row][column]=1;
                    cont += dp(n,queens+1,row+1);
                    chessboard[row][column]=0;
                }
                
            }
        }

        return cont;
    }

public:
    
    int totalNQueens(int n) {
       return dp(n,0,0);
    }
};