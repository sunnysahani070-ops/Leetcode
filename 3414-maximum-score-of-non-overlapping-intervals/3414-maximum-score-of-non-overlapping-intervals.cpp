#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int l, r, w, id;
    bool operator<(const Interval& other) const {
        if (l != other.l) return l < other.l;
        return r < other.r;
    }
};

struct State {
    long long score;
    vector<int> path;
};

bool is_better(const State& a, const State& b) {
    if (a.score != b.score) return a.score > b.score;
    return a.path < b.path; 
}

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        sort(arr.begin(), arr.end());

        vector<vector<State>> dp(n + 1, vector<State>(5, {0LL, {}}));

        for (int i = n - 1; i >= 0; --i) {
            int low = i + 1, high = n;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (arr[mid].l > arr[i].r) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            int next_idx = low;

            for (int k = 1; k <= 4; ++k) {
                State skip = dp[i + 1][k];
                
                State take;
                take.score = arr[i].w + dp[next_idx][k - 1].score;
                take.path = dp[next_idx][k - 1].path;
                take.path.push_back(arr[i].id);
                sort(take.path.begin(), take.path.end());

                if (is_better(take, skip)) {
                    dp[i][k] = take;
                } else {
                    dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].path;
    }
};