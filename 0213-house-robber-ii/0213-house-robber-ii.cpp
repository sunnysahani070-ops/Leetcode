class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Return the max of robbing (0 to n-2) or (1 to n-1)
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
    
private:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;
        
        for (int i = start; i <= end; ++i) {
            int current = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};