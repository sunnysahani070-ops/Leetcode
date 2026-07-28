class Solution {
private:
    int fmemo(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1; 
        if (dp[i][j] != -1) return dp[i][j];
        
        
        if (s[i] == t[j]) {
            return dp[i][j] = fmemo(i - 1, j - 1, s, t, dp);
        }
        
        
        int del = fmemo(i - 1, j, s, t, dp);   
        int ins = fmemo(i, j - 1, s, t, dp);     
        int rep = fmemo(i - 1, j - 1, s, t, dp); 
        
        return dp[i][j] = 1 + min({del, ins, rep});
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fmemo(n - 1, m - 1, word1, word2, dp);
    }
};