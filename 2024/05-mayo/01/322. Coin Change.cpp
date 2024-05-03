class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> memo(amount + 1, INT_MAX);
        memo[0] = 0; // No se necesita ninguna moneda para hacer el monto 0

        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0 && memo[i - coins[j]] != INT_MAX) {
                    memo[i] = min(memo[i], memo[i - coins[j]] + 1);
                }
            }
        }

        return (memo[amount] == INT_MAX) ? -1 : memo[amount];
    }
};