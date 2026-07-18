class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        int min_val = *min_it;
        int max_val = *max_it;
        
        
        unordered_set<int> present_elements(nums.begin(), nums.end());
        
        vector<int> missing_elements;
        
        
        for (int i = min_val; i <= max_val; ++i) {
            if (present_elements.find(i) == present_elements.end()) {
                missing_elements.push_back(i);
            }
        }
        
        return missing_elements;
    }
};