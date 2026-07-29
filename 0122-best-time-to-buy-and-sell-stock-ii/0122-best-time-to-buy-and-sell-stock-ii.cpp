class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int holding = 0; holding <= 1; holding++) {
                if (holding) {
                    dp[i][holding] = max(prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    dp[i][holding] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
            }
        }

        return dp[0][0];
    }
};