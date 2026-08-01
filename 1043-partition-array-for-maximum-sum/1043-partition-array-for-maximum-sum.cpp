class Solution {
private:
    int solve(int i, vector<int>& arr, int k, vector<int>& memo) {
        int n = arr.size();
        // Base case: if we've reached the end of the array
        if (i == n) return 0;
        
        // Return already calculated result
        if (memo[i] != -1) return memo[i];
        
        int maxSum = 0;
        int maxVal = 0;
        
        // Try all possible partition lengths from 1 to k
        for (int j = i; j < min(n, i + k); ++j) {
            maxVal = max(maxVal, arr[j]);
            int currentSum = (j - i + 1) * maxVal + solve(j + 1, arr, k, memo);
            maxSum = max(maxSum, currentSum);
        }
        
        return memo[i] = maxSum;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> memo(n, -1);
        return solve(0, arr, k, memo);
    }
};