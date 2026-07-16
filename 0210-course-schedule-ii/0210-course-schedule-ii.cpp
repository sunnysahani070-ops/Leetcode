class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        
        for (const auto& edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        
        int visitedCount = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visitedCount++;
            
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                    ans.push_back(neighbor);
                }
            }
        }
        
        
        if (visitedCount == numCourses) {
            return ans;
        }
        
        
        return {}; 
    }
};