#include <vector>
#include <numeric>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int minimumDifference(std::vector<int>& nums) {
        int total_len = nums.size();
        int n = total_len / 2;
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        // dp_left[i] stores all unique sums using exactly 'i' elements from the left half
        std::vector<std::unordered_set<int>> dp_left(n + 1);
        dp_left[0].insert(0);
        
        // Populate DP for the left half
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            // Loop backwards to prevent using the same element multiple times in one step
            for (int k = n; k >= 1; --k) {
                for (int prev_sum : dp_left[k - 1]) {
                    dp_left[k].insert(prev_sum + num);
                }
            }
        }
        
        // dp_right[i] stores all unique sums using exactly 'i' elements from the right half
        std::vector<std::unordered_set<int>> dp_right(n + 1);
        dp_right[0].insert(0);
        
        // Populate DP for the right half
        for (int i = n; i < total_len; ++i) {
            int num = nums[i];
            for (int k = n; k >= 1; --k) {
                for (int prev_sum : dp_right[k - 1]) {
                    dp_right[k].insert(prev_sum + num);
                }
            }
        }
        
        // Convert the right DP sets to sorted vectors for binary search
        std::vector<std::vector<int>> right_sums(n + 1);
        for (int k = 0; k <= n; ++k) {
            right_sums[k].assign(dp_right[k].begin(), dp_right[k].end());
            std::sort(right_sums[k].begin(), right_sums[k].end());
        }
        
        int min_diff = INT_MAX;
        
        // Combine results using binary search
        for (int k = 0; k <= n; ++k) {
            const auto& r_list = right_sums[n - k];
            
            for (int l_sum : dp_left[k]) {
                int target = totalSum / 2 - l_sum;
                auto it = std::lower_bound(r_list.begin(), r_list.end(), target);
                
                // Option 1: The element at or just above target
                if (it != r_list.end()) {
                    int sum1 = l_sum + *it;
                    int sum2 = totalSum - sum1;
                    min_diff = std::min(min_diff, std::abs(sum1 - sum2));
                }
                
                // Option 2: The element just below target
                if (it != r_list.begin()) {
                    auto prev_it = std::prev(it);
                    int sum1 = l_sum + *prev_it;
                    int sum2 = totalSum - sum1;
                    min_diff = std::min(min_diff, std::abs(sum1 - sum2));
                }
            }
        }
        
        return min_diff;
    }
};