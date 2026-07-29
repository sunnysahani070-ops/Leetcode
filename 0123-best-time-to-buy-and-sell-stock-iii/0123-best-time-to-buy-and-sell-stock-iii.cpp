class Solution {
    long long solve(int i, int holding, int count, vector<int>& prices, vector<vector<vector<long long>>>& dp) {
        if (i == prices.size()) return 0;
        if (count > 2) return 0;
        
        if (dp[i][holding][count] != -1) return dp[i][holding][count];
        
        long long profit = 0;
        if (holding) {
            long long sell = prices[i] + solve(i + 1, 0, count, prices, dp);
            long long skip = solve(i + 1, 1, count, prices, dp);
            profit = max(sell, skip);
        } else {
            long long buy = -prices[i] + solve(i + 1, 1, count + 1, prices, dp);
            long long skip = solve(i + 1, 0, count, prices, dp);
            profit = max(buy, skip);
        }
        return dp[i][holding][count] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(3, -1)));
        return solve(0, 0, 0, prices, dp);
    }
};