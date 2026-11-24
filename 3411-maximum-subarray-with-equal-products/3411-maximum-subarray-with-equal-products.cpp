#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int g = 0;
            int l = 1;

            for (int j = i; j < n; ++j) {
                if (prod > 2520LL * 10) {
                    break;
                }
                prod *= nums[j];
                g = (j == i) ? nums[j] : gcd(g, nums[j]);
                l = (j == i) ? nums[j] : lcm(l, nums[j]);

                if (prod == 1LL * l * g) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};