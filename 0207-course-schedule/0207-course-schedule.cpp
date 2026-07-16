class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            // pre[1] must be taken before pre[0] -> Edge from pre[1] to pre[0]
            adj[pre[1]].push_back(pre[0]);
        }
        
        // State array: 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> state(numCourses, 0);
        
        // Step 2: Perform DFS on each unvisited node
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state)) {
                    return false; // Cycle detected, cannot finish
                }
            }
        }
        
        return true; // No cycles found, can finish all courses
    }
    
private:
    bool hasCycle(int node, const vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) return true;  // Cycle detected!
        if (state[node] == 2) return false; // Already verified safe
        
        // Mark current node as 'visiting'
        state[node] = 1;
        
        // Visit all neighbors
        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor, adj, state)) {
                return true;
            }
        }
        
        // Mark node as 'visited' (safe) after checking all descendants
        state[node] = 2;
        return false;
    }
};