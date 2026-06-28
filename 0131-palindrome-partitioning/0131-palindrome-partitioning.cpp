class Solution {
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void solve(int start, string &s, vector<string> &temp,
               vector<vector<string>> &ans) {

        // Base case: entire string has been partitioned
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        // Try every possible substring starting from 'start'
        for (int end = start; end < s.size(); end++) {

            // If current substring is a palindrome
            if (isPalindrome(s, start, end)) {

                // Choose
                temp.push_back(s.substr(start, end - start + 1));

                // Explore the remaining string
                solve(end + 1, s, temp, ans);

                // Backtrack
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(0, s, temp, ans);

        return ans;
    }
};