#include <vector>
#include <unordered_map>

class Solution {
public:
    int countQuadruplets(std::vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        std::unordered_map<int, int> count;
        for (int b = n - 3; b >= 1; --b) {
            int c = b + 1;
            
            for (int d = c + 1; d < n; ++d) {
                count[nums[d] - nums[c]]++;
            }
            
            for (int a = 0; a < b; ++a) {
                int sum = nums[a] + nums[b];
                if (count.count(sum)) {
                    res += count[sum];
                }
            }
        }
        
        return res;
    }
};