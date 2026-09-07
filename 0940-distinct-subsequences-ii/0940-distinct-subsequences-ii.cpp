class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        vector<long long> dp(26, 0);
        long long total = 0;
        
        for (char c : s) {
            int idx = c - 'a';
            long long new_added = (total + 1 - dp[idx]) % MOD;
            
            if (new_added < 0) {
                new_added += MOD;
            }
            total = (total + new_added) % MOD;
            dp[idx] = (dp[idx] + new_added) % MOD;
        }
        
        return total;
    }
};