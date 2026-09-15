class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xor_sum = 0;
        for (int num : nums) {
            xor_sum ^= num;
        }
        return __builtin_popcount(xor_sum ^ k);
    }
};