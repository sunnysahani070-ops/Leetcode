class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long min_r = ranks[0];
        for (int r : ranks) {
            if (r < min_r) min_r = r;
        }
        
        long long high = 1LL * min_r * cars * cars;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long repaired_cars = 0;
            
            for (int r : ranks) {
                repaired_cars += sqrt(mid / r);
            }
            
            if (repaired_cars >= cars) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};