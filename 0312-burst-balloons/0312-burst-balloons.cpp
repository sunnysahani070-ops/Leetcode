#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
private:
    int memo[302][302];

    int dp(vector<int>& nums, int left, int right) {
        if (left > right) return 0;
        if (memo[left][right] != -1) return memo[left][right];

        int max_coins = 0;
        
        for (int k = left; k <= right; ++k) {
            int coins = nums[left - 1] * nums[k] * nums[right + 1];
            coins += dp(nums, left, k - 1) + dp(nums, k + 1, right);
            max_coins = max(max_coins, coins);
        }

        return memo[left][right] = max_coins;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> extended_nums(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            extended_nums[i + 1] = nums[i];
        }

        memset(memo, -1, sizeof(memo));
        return dp(extended_nums, 1, n);
    }
};