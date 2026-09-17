class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, 1e9);
        int sum = 0;
        int left = 0;
        int ans = 1e9;
        int min_len = 1e9;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                int len = right - left + 1;
                if (left > 0 && best[left - 1] != 1e9) {
                    ans = min(ans, best[left - 1] + len);
                }
                min_len = min(min_len, len);
            }
            best[right] = min_len;
        }

        return ans == 1e9 ? -1 : ans;
    }
};