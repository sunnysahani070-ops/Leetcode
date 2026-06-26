class Solution {
    int atMost(vector<int>& nums, int k) {
        int left = 0;
        int distinct = 0;
        int ans = 0;

        unordered_map<int, int> freq;

        for (int right = 0; right < nums.size(); right++) {
            if (freq[nums[right]] == 0)
                distinct++;

            freq[nums[right]]++;

            while (distinct > k) {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0)
                    distinct--;

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};