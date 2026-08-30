class Solution {
public:
    bool canShip(const vector<int>& weights, int days, int cap) {
        int usedDays = 1;
        int load = 0;
        
        for (int w : weights) {
            if (load + w <= cap) {
                load += w;
            } else {
                usedDays++;
                load = w;
            }
        }
        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        
        for (int w : weights) {
            if (w > low) low = w;
            high += w;
        }
        
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};