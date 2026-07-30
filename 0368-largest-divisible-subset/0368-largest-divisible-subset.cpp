class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int maxLength = 1;
        int lastIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
               
                if (nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        
        vector<int> result;
        int curr = lastIndex;
        while (parent[curr] != curr) {
            result.push_back(nums[curr]);
            curr = parent[curr];
        }
        result.push_back(nums[curr]); 
        reverse(result.begin(), result.end());
        return result;
    }
};