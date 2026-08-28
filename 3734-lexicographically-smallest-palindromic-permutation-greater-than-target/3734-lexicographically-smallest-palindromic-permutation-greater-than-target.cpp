#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int odd_cnt = 0;
        char mid = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                odd_cnt++;
                mid = i + 'a';
                freq[i]--;
            }
        }

        if (odd_cnt > 1) {
            return "";
        }

        int n = s.length();
        int half = n / 2;

        bool can_exact = true;
        vector<int> exact_freq = freq;
        for (int i = 0; i < half; ++i) {
            int c = target[i] - 'a';
            exact_freq[c] -= 2;
            if (exact_freq[c] < 0) {
                can_exact = false;
                break;
            }
        }

        if (can_exact) {
            string first_half = target.substr(0, half);
            string second_half = first_half;
            reverse(second_half.begin(), second_half.end());
            string full = first_half;
            if (n % 2 != 0) full += mid;
            full += second_half;
            if (full > target) {
                return full;
            }
        }

        for (int i = half - 1; i >= 0; --i) {
            vector<int> branch_freq = freq;
            bool possible = true;
            for (int j = 0; j < i; ++j) {
                int c = target[j] - 'a';
                branch_freq[c] -= 2;
                if (branch_freq[c] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            for (int j = (target[i] - 'a') + 1; j < 26; ++j) {
                if (branch_freq[j] >= 2) {
                    branch_freq[j] -= 2;
                    string res = target.substr(0, i);
                    res += (char)('a' + j);

                    for (int k = 0; k < 26; ++k) {
                        while (branch_freq[k] >= 2) {
                            res += (char)('a' + k);
                            branch_freq[k] -= 2;
                        }
                    }

                    string rev = res;
                    reverse(rev.begin(), rev.end());
                    if (n % 2 != 0) res += mid;
                    res += rev;
                    return res;
                }
            }
        }

        return "";
    }
};