class Solution {
private:
    int solve(int i, int holding, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size()) return 0;
        
        if (dp[i][holding] != -1) return dp[i][holding];
        
        long long profit = 0;
        if (holding) {
            long long sell = prices[i] + solve(i + 1, 0, prices, dp);
            long long skip = solve(i + 1, 1, prices, dp);
            profit = max(sell, skip);
        } else {
            long long buy = -prices[i] + solve(i + 1, 1, prices, dp);
            long long skip = solve(i + 1, 0, prices, dp);
            profit = max(buy, skip);
        }
        return dp[i][holding] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, prices, dp);
    }
};