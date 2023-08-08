class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int answer = 0;

        vector<int>best_prices(n,0);

        best_prices[n-1]=prices[n-1];

        for(int i=n-2;i>=0;i--){
            best_prices[i]=max(prices[i],best_prices[i+1]);
        }

        for(int i=0;i<n;i++){
            answer = max(answer,best_prices[i]-prices[i]);
        }
        
        return answer;
    }
};