class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); i++) {
            // odd length
            expand(s, i, i, start, maxLen);

            // even length
            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

    void expand(string& s, int l, int r, int& start, int& maxLen) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }
};