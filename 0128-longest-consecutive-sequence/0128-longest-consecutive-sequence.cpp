class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        
        int longest = 1;
        int currentLength = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue; 
            }
            if (nums[i] == nums[i - 1] + 1) {
                currentLength++;
            } else {
                longest = max(longest, currentLength);
                currentLength = 1;
            }
        }
        
        return max(longest, currentLength);
    }
};