class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;

        // XOR of all elements = x ^ y
        for (int num : nums) {
            xorAll ^= num;
        }

        // Safely find the rightmost set bit
        unsigned int mask = (unsigned int)xorAll & (-(unsigned int)xorAll);

        int num1 = 0, num2 = 0;

        // Divide numbers into two groups
        for (int num : nums) {
            if ((unsigned int)num & mask)
                num1 ^= num;
            else
                num2 ^= num;
        }

        return {num1, num2};
    }
};