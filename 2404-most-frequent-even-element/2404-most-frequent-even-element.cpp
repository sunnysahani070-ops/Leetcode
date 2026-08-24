class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        int ans = -1;

        for (int num : nums) {
            if (num % 2 == 0) {
                freq[num]++;
                if (freq[num] > maxFreq || (freq[num] == maxFreq && num < ans)) {
                    maxFreq = freq[num];
                    ans = num;
                }
            }
        }

        return ans;
    }
};