class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;
        
        // Step 1: Initialize everyone with 1 candy
        vector<int> candies(n, 1);
        
        // Step 2: Left-to-Right Pass
        // Handles cases where a child has a higher rating than their left neighbor
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // Step 3: Right-to-Left Pass
        // Handles cases where a child has a higher rating than their right neighbor
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                // max ensures we don't break a valid distribution set by the first pass
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        // Step 4: Sum all the candies together
        int totalCandies = 0;
        for (int c : candies) {
            totalCandies += c;
        }
        
        return totalCandies;
    }
};