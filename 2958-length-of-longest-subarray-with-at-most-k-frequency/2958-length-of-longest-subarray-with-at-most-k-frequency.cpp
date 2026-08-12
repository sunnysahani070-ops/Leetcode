class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = 0;
        unordered_map<int, int> mpp;
        int i = 0;
        
        for (int p = 0; p < n; p++) {
            mpp[nums[p]]++;
            
            while (mpp[nums[p]] > k) {
                mpp[nums[i]]--;
                i++;
            }
            
            mx = max(mx, p - i + 1);
        }
        
        return mx;
    }
};