#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos;
    vector<int> bit;

    void add(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    int queryBit(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum ^= bit[idx];
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return queryBit(r) ^ queryBit(l - 1);
    }

    int dfs(int v, int p, int d) {
        int size = 1;
        int max_c_size = 0;
        depth[v] = d;
        parent[v] = p;
        for (int c : adj[v]) {
            if (c != p) {
                int c_size = dfs(c, v, d + 1);
                size += c_size;
                if (c_size > max_c_size) {
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1) {
            decompose(heavy[v], h);
        }
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v]) {
                decompose(c, c);
            }
        }
    }

    int queryPath(int a, int b) {
        int res = 0;
        while (head[a] != head[b]) {
            if (depth[head[a]] > depth[head[b]]) {
                swap(a, b);
            }
            res ^= rangeQuery(pos[head[b]], pos[b]);
            b = parent[head[b]];
        }
        if (depth[a] > depth[b]) {
            swap(a, b);
        }
        res ^= rangeQuery(pos[a], pos[b]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        cur_pos = 0;

        dfs(0, 0, 0);
        decompose(0, 0);

        bit.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            add(pos[i], 1 << (s[i] - 'a'));
        }

        vector<bool> ans;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int old_val = 1 << (s[u] - 'a');
                int new_val = 1 << (c - 'a');
                add(pos[u], old_val ^ new_val);
                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;
                int mask = queryPath(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};