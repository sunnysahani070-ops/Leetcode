class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int minSum = nums[i] + nums[i + 1] + nums[i + 2];
            if (minSum > target) {
                if (abs(minSum - target) < abs(closestSum - target)) {
                    closestSum = minSum;
                }
                break;
            }
            int maxSum = nums[i] + nums[n - 1] + nums[n - 2];
            if (maxSum < target) {
                if (abs(maxSum - target) < abs(closestSum - target)) {
                    closestSum = maxSum;
                }
                continue; 
            }

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int currentSum = nums[i] + nums[j] + nums[k];

                if (currentSum == target) {
                    return currentSum; 
                }

                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) j++; 
                } else {
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) k--; 
                }
            }
        }
        return closestSum;
    }
};