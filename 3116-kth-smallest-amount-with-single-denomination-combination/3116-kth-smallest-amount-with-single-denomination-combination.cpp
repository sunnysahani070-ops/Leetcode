#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<pair<long long, int>> subsets;
        
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long lcm_val = 1;
            int set_bits = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    lcm_val = std::lcm(lcm_val, (long long)coins[i]);
                    set_bits++;
                }
            }
            subsets.push_back({lcm_val, set_bits});
        }
        
        long long left = 1;
        long long right = 50000000000LL;
        long long result = right;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            
            for (const auto& subset : subsets) {
                if (subset.second % 2 != 0) {
                    count += mid / subset.first;
                } else {
                    count -= mid / subset.first;
                }
            }
            
            if (count >= k) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};