class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int i = 0;
        int mx = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            count[nums[j]]++;
            
            while (count[nums[j]] > k) {
                count[nums[i]]--;
                i++;
            }
            
            mx = max(mx, j - i + 1);
        }
        
        return mx;
    }
};