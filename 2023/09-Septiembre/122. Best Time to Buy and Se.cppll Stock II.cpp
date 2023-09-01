class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        int n = prices.size();
        int pos = 0;
        int sum = 0;

        for(int i=1;i<n;i++){

            if(prices[i]<prices[i-1]){
                sum+=prices[i-1]-prices[pos];
                pos=i;
            }

        }

        if(pos!=n-1){
            sum+=prices[n-1]-prices[pos];
        }

        return sum;
    }
};