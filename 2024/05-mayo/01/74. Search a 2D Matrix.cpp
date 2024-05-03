class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {

        int left  = 0;
        int n = nums.size();
        int m = nums[0].size();
        int right = n*m-1;
        int mid = 0;


        while(left <= right ){
            
            mid = (left + right) / 2;

            pair<int,int> pos = makePare(mid,n,m);

            //cout<<pos.first<<" "<<pos.second<<endl;
            cout<<nums[pos.first][pos.second]<<endl;
            if(nums[pos.first][pos.second] == target){
                return true;
            }
            else if( nums[pos.first][pos.second] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
            cout<<"left :"<<left<<" "<<right<<endl;
        }

        return false;

    }
private:
    pair<int,int>makePare(int num,int n,int m){
        
        //cout<<num<<" "<<n<<" "<<m<<endl;

        int i = num / m;
        int j = num % m; // Calcula el índice de la columna correctamente

        if (i >= n) {
            i = n - 1;
        }

        if(num == 0){
            i = 0;
            j = 0;
        }

        if(num == n*m-1){
            i = n-1;
            j = m-1;
        }
        //cout<<i<<" "<<j<<endl;
        return {i,j};
    }

};