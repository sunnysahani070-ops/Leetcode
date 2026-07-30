class Solution {
private:
    int solve(int idx, int pidx, const vector<int>& nums, vector<vector<int>>& memo) {
    
        if (idx == nums.size()) return 0;
        
        
        if (memo[idx][pidx + 1] != -1) {
            return memo[idx][pidx + 1];
        }
        
        int len = solve(idx + 1, pidx, nums, memo);
        
        
        if (pidx == -1 || nums[idx] > nums[pidx]) {
            len = max(len, 1 + solve(idx + 1, idx, nums, memo));
        }
        
        return memo[idx][pidx + 1] = len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, memo);
    }
};