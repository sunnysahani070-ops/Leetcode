#include <string>

class Solution {
public:
    int repeatedStringMatch(std::string a, std::string b) {
        int n = a.length();
        int m = b.length();
        
        long long BASE = 31;
        long long MOD = 1e9 + 7;
        
        long long targetHash = 0;
        long long power = 1;
        
        for (int i = 0; i < m; i++) {
            targetHash = (targetHash * BASE + (b[i] - 'a' + 1)) % MOD;
            if (i < m - 1) {
                power = (power * BASE) % MOD;
            }
        }
        
        int totalRepeats = (m + n - 1) / n;
        long long currentHash = 0;
        
        for (int i = 0; i < m; i++) {
            char c = a[i % n];
            currentHash = (currentHash * BASE + (c - 'a' + 1)) % MOD;
        }
        
        if (currentHash == targetHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (a[j % n] != b[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return totalRepeats;
            }
        }
        
        for (int i = m; i < (totalRepeats + 1) * n; i++) {
            char removeChar = a[(i - m) % n];
            char addChar = a[i % n];
            
            currentHash = (currentHash - (removeChar - 'a' + 1) * power) % MOD;
            if (currentHash < 0) currentHash += MOD;
            
            currentHash = (currentHash * BASE + (addChar - 'a' + 1)) % MOD;
            
            if (currentHash == targetHash) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (a[(i - m + 1 + j) % n] != b[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    int startIdx = i - m + 1;
                    int endIdx = i;
                    int requiredLen = endIdx + 1;
                    return (requiredLen + n - 1) / n;
                }
            }
        }
        
        return -1;
    }
};