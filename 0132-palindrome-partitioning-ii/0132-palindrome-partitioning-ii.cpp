class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n);

        for (int i = 0; i < n; ++i) {
            int minCuts = i; 
            
            for (int j = 0; j <= i; ++j) {
                
                if (s[j] == s[i] && (i - j <= 2 || isPalindrome[j + 1][i - 1])) {
                    isPalindrome[j][i] = true;
                    
                    if (j == 0) {
                        minCuts = 0; 
                    } else {
                        minCuts = min(minCuts, dp[j - 1] + 1);
                    }
                }
            }
            dp[i] = minCuts;
        }

        return dp[n - 1];
    }
};