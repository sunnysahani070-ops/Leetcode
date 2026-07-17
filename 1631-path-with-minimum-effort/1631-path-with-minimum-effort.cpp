#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Fixed: Properly nested 2D vector initialization
        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            int current_effort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if (r == rows - 1 && c == cols - 1) {
                return current_effort;
            }
            
            if (current_effort > dist[r][c]) continue;
            
            for (int i = 0; i < 4; i++) {
                int newR = r + dr[i];
                int newC = c + dc[i];
                
                if (newR >= 0 && newR < rows && newC >= 0 && newC < cols) {
                    int step_effort = abs(heights[r][c] - heights[newR][newC]);
                    int new_path_effort = max(current_effort, step_effort);
                    
                    if (new_path_effort < dist[newR][newC]) {
                        dist[newR][newC] = new_path_effort;
                        pq.push({new_path_effort, {newR, newC}});
                    }
                }
            }
        }
        
        return 0;
    }
};