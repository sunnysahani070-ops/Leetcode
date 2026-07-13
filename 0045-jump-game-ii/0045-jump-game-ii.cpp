class Solution {
public:
    int jump(vector<int>& nums) {
        // If the array has only 1 element, you're already at the end.
        if (nums.size() <= 1) return 0;
        
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // We don't need to process the last element because once we 
        // reach or can cross it, we stop.
        for (int i = 0; i < nums.size() - 1; i++) {
            // Track the furthest index we can possibly reach from the current window
            farthest = max(farthest, i + nums[i]);
            
            // If we have reached the end of the current jump's range
            if (i == current_end) {
                jumps++;
                current_end = farthest; // Update the boundary for the next jump
                
                // Optimization: If the next range already reaches the end, we can break early
                if (current_end >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};