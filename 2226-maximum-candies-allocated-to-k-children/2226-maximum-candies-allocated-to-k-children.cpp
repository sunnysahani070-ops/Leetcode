class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for (int c : candies) {
            sum += c;
        }
        
        if (sum < k) {
            return 0;
        }
        
        long long low = 1;
        long long high = sum / k; 
        int ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            
            for (int c : candies) {
                count += c / mid;
            }
            
            if (count >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};