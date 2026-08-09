class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        return solve(piles, suffixSum, dp, 0, 1);
    }

private:
    int solve(const vector<int>& piles, const vector<int>& suffixSum, vector<vector<int>>& dp, int i, int m) {
        int n = piles.size();
        
        if (i + 2 * m >= n) {
            return suffixSum[i];
        }

        if (dp[i][m] != 0) {
            return dp[i][m];
        }

        int maxStones = 0;
        for (int x = 1; x <= 2 * m; ++x) {
            int opponentStones = solve(piles, suffixSum, dp, i + x, max(m, x));
            int currentStones = suffixSum[i] - opponentStones;
            maxStones = max(maxStones, currentStones);
        }

        return dp[i][m] = maxStones;
    }
};