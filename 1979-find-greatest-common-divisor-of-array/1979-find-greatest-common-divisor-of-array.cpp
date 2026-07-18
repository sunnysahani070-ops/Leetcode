class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_val = nums[0], max_val = nums[0];
        for (int num : nums) {
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }
        
        
        for (int i = min_val; i >= 1; --i) {
            if (min_val % i == 0 && max_val % i == 0) {
                return i;
            }
        }
        return 1;
    }
};