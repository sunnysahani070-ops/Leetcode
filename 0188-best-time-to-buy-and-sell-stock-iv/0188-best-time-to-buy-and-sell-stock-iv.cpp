class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // Optimization: If k >= n/2, it's equivalent to infinite transactions
        if (k >= n / 2) {
            int max_profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }

        
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int holding = 0; holding <= 1; ++holding) {
                for (int count = 0; count <= k; ++count) {
                    if (holding) {
                        int sell = prices[i] + next[0][count];
                        
                        int skip = next[1][count];
                        curr[holding][count] = max(sell, skip);
                    } else {
                        
                        int buy = 0;
                        if (count < k) {
                            buy = -prices[i] + next[1][count + 1];
                        }
                        
                        int skip = next[0][count];
                        curr[holding][count] = max(buy, skip);
                    }
                }
            }
            next = curr;
        }

        return next[0][0];
    }
};