#include <vector>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> orig_adj(n);
        for (int i = 1; i < n; ++i) {
            orig_adj[parent[i]].push_back(i);
        }

        vector<vector<int>> new_adj(n);
        array<int, 26> last_seen;
        last_seen.fill(-1);

        auto reassign = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = last_seen[c];

            if (u != 0) {
                int target_parent = (prev != -1) ? prev : parent[u];
                new_adj[target_parent].push_back(u);
            }

            last_seen[c] = u;
            for (int v : orig_adj[u]) {
                self(self, v);
            }
            last_seen[c] = prev;
        };

        reassign(reassign, 0);

        vector<int> ans(n, 0);
        auto calc_size = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : new_adj[u]) {
                sz += self(self, v);
            }
            return ans[u] = sz;
        };

        calc_size(calc_size, 0);
        return ans;
    }
};