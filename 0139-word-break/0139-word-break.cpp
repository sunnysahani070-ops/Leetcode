class Solution {
public:
    bool solve(int index, string &s, unordered_set<string> &dict,
               vector<int> &dp) {
        // Reached the end of the string
        if (index == s.size())
            return true;

        // Already computed
        if (dp[index] != -1)
            return dp[index];

        // Try every possible word starting at 'index'
        for (int end = index; end < s.size(); end++) {
            string word = s.substr(index, end - index + 1);

            if (dict.count(word) && solve(end + 1, s, dict, dp))
                return dp[index] = true;
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size(), -1); // -1 = not computed

        return solve(0, s, dict, dp);
    }
};