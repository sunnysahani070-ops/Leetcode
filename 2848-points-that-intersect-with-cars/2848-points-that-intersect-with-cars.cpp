class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> diff(102, 0);
        for (const auto& interval : nums) {
            diff[interval[0]]++;
            diff[interval[1] + 1]--;
        }

        int count = 0;
        int current = 0;
        for (int i = 1; i <= 100; ++i) {
            current += diff[i];
            if (current > 0) {
                count++;
            }
        }

        return count;
    }
};