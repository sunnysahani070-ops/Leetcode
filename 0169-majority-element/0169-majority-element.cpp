class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Optimizes standard I/O operations for faster execution times on LeetCode
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            // Condenses the if/else into a single line for cleaner reading
            count += (num == candidate) ? 1 : -1; 
        }
        
        return candidate;
    }
};