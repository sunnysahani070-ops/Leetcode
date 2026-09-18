#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getRight(int i, const vector<int>& first, const vector<int>& last, const string& s) {
        int right = last[i];
        for (int j = first[i]; j <= right; ++j) {
            if (first[s[j] - 'a'] < first[i]) {
                return -1;
            }
            right = max(right, last[s[j] - 'a']);
        }
        return right;
    }

    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, s.length());
        vector<int> last(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; ++i) {
            if (last[i] != -1) {
                int right = getRight(i, first, last, s);
                if (right != -1) {
                    intervals.push_back({right, first[i]});
                }
            }
        }

        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int prev_right = -1;
        for (auto& interval : intervals) {
            if (interval.second > prev_right) {
                ans.push_back(s.substr(interval.second, interval.first - interval.second + 1));
                prev_right = interval.first;
            }
        }

        return ans;
    }
};