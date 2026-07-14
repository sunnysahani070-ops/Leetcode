#include <vector>
#include <queue>

class Solution {
private:
    void bfs(int start, const std::vector<std::vector<int>>& isConnected, std::vector<int>& vis) {
        std::queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

           
            for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
                
                if (isConnected[node][neighbor] == 1 && !vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int n = isConnected.size();
        std::vector<int> vis(n, 0);
        int province = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                province++;
                bfs(i, isConnected, vis); 
            }
        }
        
        return province;
    }
};