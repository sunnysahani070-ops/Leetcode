class Solution {
public:
    int atMost(string& s, int k) {
        int left = 0;
        int ans = 0;
        int distinct = 0;
        int freq[3] = {0};

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right] - 'a'] == 0)
                distinct++;

            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;

                if (freq[s[left] - 'a'] == 0)
                    distinct--;

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int numberOfSubstrings(string s) {
        return atMost(s, 3) - atMost(s, 2);
    }
};