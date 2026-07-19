class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Create a DP table (or modify the last row in-place)
        vector<int> dp = triangle[n - 1];
        
        // Move from the second-to-last row up to the top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // The minimum path for this cell is its value plus
                // the minimum of the two adjacent cells below it
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        
        return dp[0];
    }
};