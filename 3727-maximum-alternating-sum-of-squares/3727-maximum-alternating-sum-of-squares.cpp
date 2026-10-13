class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            squares[i] = val * val;
        }
        sort(squares.begin(), squares.end());
        
        long long score = 0;
        int positiveCount = (n + 1) / 2;
        int negativeCount = n / 2;
        
        for (int i = 0; i < negativeCount; ++i) {
            score -= squares[i];
        }
        for (int i = negativeCount; i < n; ++i) {
            score += squares[i];
        }
        return score;
    }
};