class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        for (int k = n - 1; k >= 0; k--) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[k] = nums[left] * nums[left];
                left++;
            } else {
                result[k] = nums[right] * nums[right];
                right--;
            }
        }
        
        return result;
    }
};