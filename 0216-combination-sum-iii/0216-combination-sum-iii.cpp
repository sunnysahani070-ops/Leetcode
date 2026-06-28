class Solution {
    void magic(int k, int n, int start,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        if (k == 0) {
            if (n == 0)
                ans.push_back(temp);
            return;
        }

        for (int j = start; j <= 9; j++) {

            if (j > n)
                break;

            temp.push_back(j);

            magic(k - 1, n - j, j + 1, temp, ans);

            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> temp;

        magic(k, n, 1, temp, ans);

        return ans;
    }
};