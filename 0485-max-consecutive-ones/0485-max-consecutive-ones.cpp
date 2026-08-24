class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int current_count = 0;
        
        
        for (int num : nums) {
            if (num == 1) {
                current_count++;
            } else {
                if (current_count > max_count) {
                    max_count = current_count;
                }
                current_count = 0;
            }
        }
        
        return current_count > max_count ? current_count : max_count;
    }
};