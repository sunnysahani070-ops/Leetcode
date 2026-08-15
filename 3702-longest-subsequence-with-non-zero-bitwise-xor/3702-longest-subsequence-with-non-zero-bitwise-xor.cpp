class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        int zero_count = 0;
        int n = nums.size();
        
        for (int num : nums) {
            total_xor ^= num;
            if (num == 0) {
                zero_count++;
            }
        }
        
        if (zero_count == n) {
            return 0;
        }
        
        if (total_xor != 0) {
            return n;
        }
        
        return n - 1;
    }
};