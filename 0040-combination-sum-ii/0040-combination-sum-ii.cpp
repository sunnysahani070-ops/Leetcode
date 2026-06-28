class Solution {
    void solve(vector<int>& nums, int index, int target,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1])
                continue;

            // Since array is sorted
            if (nums[i] > target)
                break;

            temp.push_back(nums[i]);

            solve(nums, i + 1, target - nums[i], temp, ans);

            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, 0, target, temp, ans);

        return ans;
    }
};