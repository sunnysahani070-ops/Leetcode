class Solution {
public:
    int countPalindromes(string s) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        
        // prefPairs[i][x][y] stores the number of subsequences "xy" in s[0...i-1]
        // suffPairs[i][x][y] stores the number of subsequences "xy" in s[i+1...n-1]
        vector<vector<vector<int>>> prefPairs(n, vector<vector<int>>(10, vector<int>(10, 0)));
        vector<vector<vector<int>>> suffPairs(n, vector<vector<int>>(10, vector<int>(10, 0)));
        
        // Fill prefPairs from left to right
        vector<int> cnt(10, 0);
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                prefPairs[i] = prefPairs[i - 1]; // Inherit previous counts
            }
            int cur = s[i] - '0';
            for (int x = 0; x < 10; ++x) {
                prefPairs[i][x][cur] += cnt[x]; // Add new pairs ending with s[i]
            }
            cnt[cur]++;
        }
        
        // Fill suffPairs from right to left
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1) {
                suffPairs[i] = suffPairs[i + 1]; // Inherit previous counts
            }
            int cur = s[i] - '0';
            for (int y = 0; y < 10; ++y) {
                suffPairs[i][cur][y] += cnt[y]; // Add new pairs starting with s[i]
            }
            cnt[cur]++;
        }
        
        long long totalPalindromes = 0;
        
        // Iterate over all possible center indices (from 2 to n-3)
        for (int i = 2; i < n - 2; ++i) {
            for (int x = 0; x < 10; ++x) {
                for (int y = 0; y < 10; ++y) {
                    long long leftCount = prefPairs[i - 1][x][y];
                    long long rightCount = suffPairs[i + 1][y][x];
                    
                    if (leftCount > 0 && rightCount > 0) {
                        totalPalindromes = (totalPalindromes + leftCount * rightCount) % MOD;
                    }
                }
            }
        }
        
        return totalPalindromes;
    }
};