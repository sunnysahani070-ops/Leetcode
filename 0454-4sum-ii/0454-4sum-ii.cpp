class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int, int> sumMap;
        sumMap.reserve(nums1.size() * nums2.size());
        
        for (int a : nums1) {
            for (int b : nums2) {
                sumMap[a + b]++;
            }
        }
        
        int count = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                int target = -(c + d);
               
                auto it = sumMap.find(target); 
                if (it != sumMap.end()) {
                    count += it->second;
                }
            }
        }
        
        return count;
    }
};