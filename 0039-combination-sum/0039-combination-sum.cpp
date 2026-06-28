class Solution {
    void solve(vector<int>& nums, int index, int sum, int k,
               vector<vector<int>>& ans, vector<int>& temp) {
                if (sum > k)
        return;

        if (index == nums.size()) {
            if (sum == k)
                ans.push_back(temp);
            return;
        }

        // Take current element
        temp.push_back(nums[index]);
        solve(nums, index, sum + nums[index], k, ans, temp);
        temp.pop_back();

        // Skip current element
        solve(nums, index + 1, sum, k, ans, temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, 0, 0, target, ans, temp);

        return ans;
    }
};