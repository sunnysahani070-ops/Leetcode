class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> present(n + 1, false);
        
        for (int num : nums) {
            if (num % k == 0) {
                int multiple_index = num / k;
                if (multiple_index <= n) {
                    present[multiple_index] = true;
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (!present[i]) {
                return k * i;
            }
        }
        
        return k * (n + 1);
    }
};