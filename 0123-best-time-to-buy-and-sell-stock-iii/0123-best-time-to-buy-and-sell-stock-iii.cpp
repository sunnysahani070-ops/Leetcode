class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        
        vector<vector<long long>> next(2, vector<long long>(3, 0));
        vector<vector<long long>> curr(2, vector<long long>(3, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int holding = 0; holding <= 1; ++holding) {
                for (int count = 0; count <= 2; ++count) {
                    long long profit = 0;
                    if (holding) {
                        long long sell = prices[i] + next[0][count];
                        long long skip = next[1][count];
                        profit = max(sell, skip);
                    } else {
                        long long buy = 0;
                        if (count < 2) {
                            buy = -prices[i] + next[1][count + 1];
                        }
                        long long skip = next[0][count];
                        profit = max(buy, skip);
                    }
                    curr[holding][count] = profit;
                }
            }
            next = curr;
        }

        return next[0][0];
    }
};