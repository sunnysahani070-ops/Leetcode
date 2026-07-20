class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<vector<int>> left(n + 1), right(n + 1);

        // Generate subset sums for left half
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[i];
                }
            }
            left[cnt].push_back(sum);
        }

        // Generate subset sums for right half
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[n + i];
                }
            }
            right[cnt].push_back(sum);
        }

        for (int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {
            for (int s1 : left[k]) {

                int target = total / 2 - s1;

                auto &vec = right[n - k];
                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int chosen = s1 + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }

                if (it != vec.begin()) {
                    --it;
                    int chosen = s1 + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }
            }
        }

        return ans;
    }
};