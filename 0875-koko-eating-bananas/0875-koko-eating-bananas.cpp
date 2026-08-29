class Solution {
    long long totalhr(vector<int>& arr, int hour) {
        long long totalhrs = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalhrs += (arr[i] + hour - 1) / hour;
        }
        return totalhrs;
    }

    int maxel(vector<int>& arr) {
        int mx = 0;
        for (int x : arr) {
            mx = max(mx, x);
        }
        return mx;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxel(piles);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (totalhr(piles, mid) <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};