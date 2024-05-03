class Solution {

private:
    int memo[50];

public:

    int climbStairs(int n) {

        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        if(n<=0){
            return 0;
        }

        if( memo[n] == 0){

            
            if( memo[n-1]==0 ){
                memo[n-1] = climbStairs(n-1);
            }
            if( memo[n-2]==0 ){
                memo[n-2] = climbStairs(n-2);
            }

            int left = memo[n-1];
            int right = memo[n-2];
            memo[n] =left+right;
            //cout<<n<<" left :"<<left<<" right: "<<right<<" sum: "<<memo[n]<<endl;
           
        }

     
        
        return memo[n];
    }
};