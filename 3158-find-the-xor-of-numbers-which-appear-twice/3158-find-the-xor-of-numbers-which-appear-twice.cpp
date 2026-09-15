class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        bool seen[51] = {false};
        for (int num : nums) {
            if (seen[num]) {
                ans ^= num;
            }
            seen[num] = true;
        }
        return ans;
    }
};