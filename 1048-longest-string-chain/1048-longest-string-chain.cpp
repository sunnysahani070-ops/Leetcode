class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        unordered_map<string, int> dp;
        int maxChain = 0;
        
        for (const string& word : words) {
            int currentLen = 1;
            
            for (int i = 0; i < word.length(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(predecessor) != dp.end()) {
                    currentLen = max(currentLen, dp[predecessor] + 1);
                }
            }
            dp[word] = currentLen;
            maxChain = max(maxChain, currentLen);
        }
        
        return maxChain;
    }
};