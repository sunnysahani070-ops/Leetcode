class Solution {
    void backtrack(const vector<int>& nums, int index, int current_or, int max_or, int& count) {
        if (index == nums.size()) {
            if (current_or == max_or) {
                count++;
            }
            return;
        }
        
        backtrack(nums, index + 1, current_or | nums[index], max_or, count);
        backtrack(nums, index + 1, current_or, max_or, count);
    }
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int num : nums) {
            max_or |= num;
        }
        
        int count = 0;
        backtrack(nums, 0, 0, max_or, count);
        return count;
    }
};