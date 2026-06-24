class Solution {
public:
    string reverseWords(string s) {
        vector<string> t;
        string result = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                result += s[i];
            } else {
                if (!result.empty()) {
                    t.insert(t.begin(), result);
                    result = "";
                }
            }
        }

        if (!result.empty()) {
            t.insert(t.begin(), result);
        }

        string ans;
        for (int i = 0; i < t.size(); i++) {
            if (i > 0) ans += " ";
            ans += t[i];
        }

        return ans;
    }
};