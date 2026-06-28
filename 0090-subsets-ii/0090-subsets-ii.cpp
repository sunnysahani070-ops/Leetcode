class Solution {
    void subset(vector<int>& nums, int i, int n, vector<int>& temp,
                vector<vector<int>>& ans) {

        ans.push_back(temp);

        for (int j = i; j < n; j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;

            temp.push_back(nums[j]);
            subset(nums, j + 1, n, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        vector<vector<int>> ans;

        subset(nums, 0, nums.size(), temp, ans);

        return ans;
    }
};