class Solution {
public:

    vector<string> mapping = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void solve(int index,
               string &digits,
               string &current,
               vector<string> &ans) {

        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {

            current.push_back(ch);

            solve(index + 1, digits, current, ans);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if (digits.empty())
            return ans;

        string current;

        solve(0, digits, current, ans);

        return ans;
    }
};