class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = 0;
        for (int q : quantities) {
            if (q > high) {
                high = q;
            }
        }
        
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long stores_needed = 0;
            
            for (int q : quantities) {
                stores_needed += (q + mid - 1) / mid;
            }
            
            if (stores_needed <= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};