class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        // Find maximum value to determine bit length
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        int max_xor = 1;
        while (max_xor <= max_val) {
            max_xor <<= 1;
        }
        

        vector<bool> pair_xors(max_xor, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                pair_xors[nums[i] ^ nums[j]] = true;
            }
        }
        
   
        vector<bool> triplet_xors(max_xor, false);
        for (int p = 0; p < max_xor; ++p) {
            if (pair_xors[p]) {
                for (int x : nums) {
                    triplet_xors[p ^ x] = true;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < max_xor; ++i) {
            if (triplet_xors[i]) {
                count++;
            }
        }
        
        return count;
    }
};