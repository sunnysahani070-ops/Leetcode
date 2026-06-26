class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int oddCount = 0;
        int prefix = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2) {
                oddCount++;
                prefix = 0;
            }

            while (oddCount == k) {
                prefix++;

                if (nums[left] % 2)
                    oddCount--;

                left++;
            }

            ans += prefix;
        }

        return ans;
    }
};