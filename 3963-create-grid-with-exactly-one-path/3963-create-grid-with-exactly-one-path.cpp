class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '.'));
        for (int i = 1; i < m; ++i) {
            ans[i] = string(n - 1, '#') + '.';
        }
        return ans;
    }
};