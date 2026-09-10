class Solution {
private:
    void generate(int open, int close, int n, string& current, vector<string>& ans) {
        if (current.length() == n * 2) {
            ans.push_back(current);
            return;
        }
        
        if (open < n) {
            current.push_back('(');
            generate(open + 1, close, n, current, ans);
            current.pop_back();
        }
        
        if (close < open) {
            current.push_back(')');
            generate(open, close + 1, n, current, ans);
            current.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        generate(0, 0, n, current, ans);
        return ans;
    }
};