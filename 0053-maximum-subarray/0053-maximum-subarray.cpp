class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int maxSum = nums[0];
        int currentSum = 0;
        
        for (int num : nums) {
            currentSum = max(num, currentSum + num);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};