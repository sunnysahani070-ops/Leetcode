class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> curr_freq(k, 0);
        
        for (long long x : nums) {
            vector<long long> next_freq(k, 0);
            
            next_freq[x % k] += 1;
            
            for (int r = 0; r < k; ++r) {
                if (curr_freq[r] > 0) {
                    next_freq[(r * x) % k] += curr_freq[r];
                }
            }
            
            curr_freq = next_freq;
            
            for (int r = 0; r < k; ++r) {
                result[r] += curr_freq[r];
            }
        }
        
        return result;
    }
};