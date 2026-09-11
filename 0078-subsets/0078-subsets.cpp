class Solution {
    void subset(vector<int>& arr, int i, int n, vector<int>& temp,
                vector<vector<int>>& ans) {
        if (i == n) {
            ans.push_back(temp);
            return;
        };

        temp.push_back(arr[i]);
        subset(arr, i + 1, n, temp, ans);
        temp.pop_back();
        subset(arr, i + 1, n, temp, ans);
    };

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        subset(nums, 0, nums.size(), temp, ans);
        return ans;
    }
};