class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] > 0) {
            return state[node] == 2;
        }
        state[node] = 1;
        for (int next_node : graph[node]) {
            if (!dfs(next_node, graph, state)) {
                return false;
            }
        }
        state[node] = 2;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state)) {
                res.push_back(i);
            }
        }
        return res;
    }
};