class Solution {
    int calc(const vector<int>& arr, int n) {
        int parts = 1;
        int subsum = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (subsum + arr[i] <= n) {
                subsum += arr[i];
            } else {
                parts++;
                subsum = arr[i];
            }
        }

        return parts;
    }

    int sum(const vector<int>& arr) {
        int total = 0;

        for (int i = 0; i < arr.size(); i++) {
            total += arr[i];
        }

        return total;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = sum(nums);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int parts = calc(nums, mid);

            if (parts <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};